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

    forro_qr(state_vector);

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
    int i;

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
        //Gera uma saída criptografada para o bloco atual de dados de entrada
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

inline void forro_generate_bytes(stream_ctx *x, uint8_t *c, uint32_t bytes)
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
                c[i] = output[i];
            return;
        }
        for (i = 0; i < 64; ++i)
            c[i] = output[i];
        bytes -= 64;
        c += 64;
    }
}

void forro_decrypt_bytes(stream_ctx *x, const uint8_t *c, uint8_t *m, uint32_t bytes)
{
    forro_encrypt_bytes(x, c, m, bytes);
}

void forro_keystream_bytes(stream_ctx *x, uint8_t *stream, uint32_t bytes)
{
    uint32_t i;
    forro_encrypt_bytes(x, stream, stream, bytes);
}

void forro_prf(uint8_t *out, size_t outlen, const uint8_t key[KYBER_SYMBYTES], uint8_t * expnonce)
{
    stream_ctx ctx;
    forro_keysetup(&ctx, (uint8_t *)key);
    uint8_t iv[8] = { 0 };
    iv[0] = expnonce[0];
    forro_ivsetup(&ctx, iv);
    forro_keystream_bytes(&ctx, out, (uint32_t)outlen);
}

void forro_absorb(stream_ctx *ctx, const uint8_t *seed, uint8_t * expnonce)
{
    forro_keysetup(ctx, (uint8_t *)seed);
    uint8_t iv[8] = { 0 };
    iv[0] = expnonce[0];
    iv[1] = expnonce[1];

    forro_ivsetup(ctx, iv);
    forro_qr(ctx->state);
}

void forro_squeeze(uint8_t *out, size_t outbytes, stream_ctx *ctx)
{
    forro_generate_bytes(ctx, out, outbytes);
}

void forro_kdf(uint8_t *out, size_t outlen, uint8_t *in, size_t inlen)
{
    stream_ctx ctx = { 0x0 };
    uint32_t iv[2] = { 0x0 };
    size_t ctr = 0;

    while(inlen >= 32)
    {
        forro_keysetup_xor(&ctx, in);
        forro_ivsetup_xor(&ctx, (uint8_t *)iv);

        in += 32;
        inlen -= 32;

        //fazer em 32 bits!
        iv[0]++;
        if(!iv[0])
            iv[2]++;
    }

    if(inlen)
    {
        uint8_t key_rem[32] = { 0x0 };
        for(int i = 0; i < inlen; i++)
            key_rem[i] = in[i];

        forro_keysetup_xor(&ctx, key_rem);
        forro_ivsetup_xor(&ctx, (uint8_t *)iv);
    }
 
    forro_generate_bytes(&ctx, out, outlen);   
}