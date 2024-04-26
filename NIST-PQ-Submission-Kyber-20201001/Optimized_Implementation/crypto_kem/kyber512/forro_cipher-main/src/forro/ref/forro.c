#include "forro.h"
#include <stdio.h>
#pragma GCC optimize("O3")
#define rounds 7
#define ROTL(a, b) (((a) << (b)) | ((a) >> (32 - (b))))
#define Q(a, b, c, d, e) (                   \
    d += e, c ^= d, b += c, b = ROTL(b, 10), \
    a += b, e ^= a, d += e, d = ROTL(d, 27), \
    c += d, b ^= c, a += b, a = ROTL(a, 8))

inline void forro(uint8_t out[64], const uint32_t init[16])
{

    uint32_t state_vector[16];
    int i;
    for (i = 0; i < 16; i++)
    {
        state_vector[i] = init[i];
    }

    for (i = 0; i < rounds; i++)
    {
        Q(state_vector[0], state_vector[4], state_vector[8], state_vector[12], state_vector[3]);
        Q(state_vector[1], state_vector[5], state_vector[9], state_vector[13], state_vector[0]);
        Q(state_vector[2], state_vector[6], state_vector[10], state_vector[14], state_vector[1]);
        Q(state_vector[3], state_vector[7], state_vector[11], state_vector[15], state_vector[2]);
        Q(state_vector[0], state_vector[5], state_vector[10], state_vector[15], state_vector[3]);
        Q(state_vector[1], state_vector[6], state_vector[11], state_vector[12], state_vector[0]);
        Q(state_vector[2], state_vector[7], state_vector[8], state_vector[13], state_vector[1]);
        Q(state_vector[3], state_vector[4], state_vector[9], state_vector[14], state_vector[2]);
    }

    for (i = 0; i < 16; i++)
    {
        state_vector[i] = init[i] + state_vector[i];
    }
    for (i = 0; i < 16; i++)
    {
        U32TO8_LITTLE(out + 4 * i, state_vector[i]);
    }

    return;
}

inline void forro_qr(uint32_t state_vector[16])
{
    // uint32_t init[16];
    int i;
    // for (i = 0; i < 16; i++)
    // {
    //     init[i] = state_vector[i];
    // }

    for (i = 0; i < rounds; i++)
    {
        Q(state_vector[0], state_vector[4], state_vector[8], state_vector[12], state_vector[3]);
        Q(state_vector[1], state_vector[5], state_vector[9], state_vector[13], state_vector[0]);
        Q(state_vector[2], state_vector[6], state_vector[10], state_vector[14], state_vector[1]);
        Q(state_vector[3], state_vector[7], state_vector[11], state_vector[15], state_vector[2]);
        Q(state_vector[0], state_vector[5], state_vector[10], state_vector[15], state_vector[3]);
        Q(state_vector[1], state_vector[6], state_vector[11], state_vector[12], state_vector[0]);
        Q(state_vector[2], state_vector[7], state_vector[8], state_vector[13], state_vector[1]);
        Q(state_vector[3], state_vector[4], state_vector[9], state_vector[14], state_vector[2]);
    }

    // for (i = 0; i < 16; i++)
    // {
    //     state_vector[i] = init[i] + state_vector[i];
    // }

    return;
}

void forro_init()
{
    return;
}

void forro_keysetup(stream_ctx *x, uint8_t *key) //importante
{
    x->state[0] = U8TO32_LITTLE(key + 0);
    x->state[1] = U8TO32_LITTLE(key + 4);
    x->state[2] = U8TO32_LITTLE(key + 8);
    x->state[3] = U8TO32_LITTLE(key + 12);
    x->state[6] = U8TO32_LITTLE(SIGMA + 0);
    x->state[7] = U8TO32_LITTLE(SIGMA + 4);
    x->state[8] = U8TO32_LITTLE(key + 16);
    x->state[9] = U8TO32_LITTLE(key + 20);
    x->state[10] = U8TO32_LITTLE(key + 24);
    x->state[11] = U8TO32_LITTLE(key + 28);
    x->state[14] = U8TO32_LITTLE(SIGMA + 8);
    x->state[15] = U8TO32_LITTLE(SIGMA + 12);
}
void forro_keysetup_xor(stream_ctx *x, uint8_t *key) //importante
{
    x->state[0] ^= U8TO32_LITTLE(key + 0);
    x->state[1] ^= U8TO32_LITTLE(key + 4);
    x->state[2] ^= U8TO32_LITTLE(key + 8);
    x->state[3] ^= U8TO32_LITTLE(key + 12);
    x->state[6] ^= U8TO32_LITTLE(SIGMA + 0);
    x->state[7] ^= U8TO32_LITTLE(SIGMA + 4);
    x->state[8] ^= U8TO32_LITTLE(key + 16);
    x->state[9] ^= U8TO32_LITTLE(key + 20);
    x->state[10] ^= U8TO32_LITTLE(key + 24);
    x->state[11] ^= U8TO32_LITTLE(key + 28);
    x->state[14] ^= U8TO32_LITTLE(SIGMA + 8);
    x->state[15] ^= U8TO32_LITTLE(SIGMA + 12);
}

void forro_ivsetup(stream_ctx *x, uint8_t *iv) //importante
{
    x->state[4] = 0;
    x->state[5] = 0;
    x->state[12] = U8TO32_LITTLE(iv + 0);
    x->state[13] = U8TO32_LITTLE(iv + 4);
}

void forro_ivsetup_xor(stream_ctx *x, uint8_t *iv) //importante
{
    x->state[4] ^= 0;
    x->state[5] ^= 0;
    x->state[12] ^= U8TO32_LITTLE(iv + 0);
    x->state[13] ^= U8TO32_LITTLE(iv + 4);
}

inline void forro_encrypt_bytes(stream_ctx *x, const uint8_t *m, uint8_t *c, uint32_t bytes)
{
    uint8_t output[64];
    int i;

    if (!bytes)
        return;
    for (;;)
    {
        forro(output, x->state);
        x->state[4] = x->state[4] + 1;
        if (!x->state[4])
        {
            x->state[5] = x->state[5] + 1;
        }
        if (bytes <= 64)
        {
            for (i = 0; i < bytes; ++i)
                c[i] = m[i] ^ output[i];
            return;
        }
        for (i = 0; i < 64; ++i)
            c[i] = m[i] ^ output[i];
        bytes -= 64;
        c += 64;
        m += 64;
    }
}

void forro_decrypt_bytes(stream_ctx *x, const uint8_t *c, uint8_t *m, uint32_t bytes)
{
    forro_encrypt_bytes(x, c, m, bytes);
}

void forro_keystream_bytes(stream_ctx *x, uint8_t *stream, uint32_t bytes)
{
    uint32_t i;
    // for (i = 0; i < bytes; ++i)
    //     stream[i] = 0;
    forro_encrypt_bytes(x, stream, stream, bytes);
}

void forro_prf(uint8_t *out, size_t outlen, const uint8_t key[KYBER_SYMBYTES], uint8_t * expnonce)
{
    stream_ctx ctx;
    forro_keysetup(&ctx, (uint8_t *)key);
    // forro_keysetup(stream_ctx *x, uint8_t *key);
    uint8_t iv[16] = { 0 };
    iv[0] = expnonce[0];
    forro_ivsetup(&ctx, iv);
    // forro_ivsetup(str\eam_ctx *x, uint8_t *iv);
    forro_keystream_bytes(&ctx, out, (uint32_t)outlen);
}

void forro_absorb(stream_ctx *ctx, const uint8_t *seed, uint8_t * expnonce)
{
    printf("[forro] Absorb!\n");
    forro_keysetup(ctx, (uint8_t *)seed);
    // forro_keysetup(stream_ctx *x, uint8_t *key);
    uint8_t iv[16] = { 0 };
    iv[0] = expnonce[0];
    iv[1] = expnonce[1];
    printf("[forro] iv: %02x %02x\n", iv[0], iv[1]);

    forro_ivsetup(ctx, iv);
    // forro_ivsetup(str\eam_ctx *x, uint8_t *iv);
    forro_qr(ctx->state);
}

void forro_squeeze(uint8_t *out, size_t nblocks, stream_ctx *ctx)
{
    printf("[forro] Squeeze! nblocks: %d\n", nblocks);
    printf("[forro] Checking state:\n");
    for(int i = 0; i < 16; i++)
    {
        printf("%08x ", ctx->state[i]);
    }
    printf("\n");
    uint32_t outbytes = nblocks * FORRO_SIZE_BLOCK;
    printf("[forro] Checking state:\n");
    forro_keystream_bytes(ctx, out, outbytes);

    printf("[forro] Generating %d bytes\n", outbytes);
    for(int i = 0; i < outbytes; i++)
    {
    printf("%02x ", out[i]);
    }
    printf("\n");

}