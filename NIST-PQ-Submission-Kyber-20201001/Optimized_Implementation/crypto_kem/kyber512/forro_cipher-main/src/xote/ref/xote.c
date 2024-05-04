#include "xote.h"
#include <stdio.h>
#pragma GCC optimize("O3")
#define rounds 7
#define ROTL(a, b) (((a) << (b)) | ((a) >> (32 - (b))))
#define Q(a, b, c, d, e) (                   \
    d += e, c ^= d, b += c, b = ROTL(b, 10), \
    a += b, e ^= a, d += e, d = ROTL(d, 27), \
    c += d, b ^= c, a += b, a = ROTL(a, 8))

inline void xote(uint8_t out[128], const uint32_t init[16])
{
    uint32_t state_vector[16];
    uint32_t state_vector2[16];
    int i;
    for (i = 0; i < 16; i++)
    {
        state_vector[i] = init[i];
        state_vector2[i] = init[i];
    }

    state_vector2[4] = state_vector2[4] + 1;

    xote_qr(state_vector, state_vector2);

    for (i = 0; i < 16; i++)
    {
        state_vector[i] = init[i] + state_vector[i];
        state_vector2[i] = init[i] + state_vector2[i];
    }
    state_vector2[4] = state_vector2[4] + 1;
    for (i = 0; i < 16; i++)
    {
        U32TO8_LITTLE(out + 4 * i, state_vector[i]);
        U32TO8_LITTLE(out + 4 * i + 64, state_vector2[i]);
    }

    return;
}

inline void xote_qr(uint32_t state_vector[16], uint32_t state_vector2[16])
{
    int i;

    for (i = 0; i < rounds; i++)
    {
        Q(state_vector[0], state_vector[4], state_vector[8], state_vector[12], state_vector[3]);
        Q(state_vector2[0], state_vector2[4], state_vector2[8], state_vector2[12], state_vector2[3]);
        Q(state_vector[1], state_vector[5], state_vector[9], state_vector[13], state_vector[0]);
        Q(state_vector2[1], state_vector2[5], state_vector2[9], state_vector2[13], state_vector2[0]);
        Q(state_vector[2], state_vector[6], state_vector[10], state_vector[14], state_vector[1]);
        Q(state_vector2[2], state_vector2[6], state_vector2[10], state_vector2[14], state_vector2[1]);
        Q(state_vector[3], state_vector[7], state_vector[11], state_vector[15], state_vector[2]);
        Q(state_vector2[3], state_vector2[7], state_vector2[11], state_vector2[15], state_vector2[2]);
        Q(state_vector[0], state_vector[5], state_vector[10], state_vector[15], state_vector[3]);
        Q(state_vector2[0], state_vector2[5], state_vector2[10], state_vector2[15], state_vector2[3]);
        Q(state_vector[1], state_vector[6], state_vector[11], state_vector[12], state_vector[0]);
        Q(state_vector2[1], state_vector2[6], state_vector2[11], state_vector2[12], state_vector2[0]);
        Q(state_vector[2], state_vector[7], state_vector[8], state_vector[13], state_vector[1]);
        Q(state_vector2[2], state_vector2[7], state_vector2[8], state_vector2[13], state_vector2[1]);
        Q(state_vector[3], state_vector[4], state_vector[9], state_vector[14], state_vector[2]);
        Q(state_vector2[3], state_vector2[4], state_vector2[9], state_vector2[14], state_vector2[2]);
    }
    return;
}

void xote_init()
{
    return;
}

void xote_keysetup(stream_ctx *x, uint8_t *key)
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

void xote_ivsetup(stream_ctx *x, uint8_t *iv)
{
    x->state[4] = 0;
    x->state[5] = 0;
    x->state[12] = U8TO32_LITTLE(iv + 0);
    x->state[13] = U8TO32_LITTLE(iv + 4);
}

void xote_keysetup_xor(stream_ctx *x, uint8_t *key)
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

void xote_ivsetup_xor(stream_ctx *x, uint8_t *iv)
{
    x->state[4] ^= 0;
    x->state[5] ^= 0;
    x->state[12] ^= U8TO32_LITTLE(iv + 0);
    x->state[13] ^= U8TO32_LITTLE(iv + 4);
}

inline void xote_encrypt_bytes(stream_ctx *x, const uint8_t *m, uint8_t *c, uint32_t bytes)
{
    uint8_t output[128];
    int i;

    if (!bytes)
        return;
    for (;;)
    {
        xote(output, x->state);
        x->state[4] = x->state[4] + 2;
        if (!(x->state[4] >> 1))
        {
            x->state[5] = x->state[5] + 1;
        }
        if (bytes <= 128)
        {
            for (i = 0; i < bytes; ++i)
                c[i] = m[i] ^ output[i];
            return;
        }
        for (i = 0; i < 128; ++i)
            c[i] = m[i] ^ output[i];
        bytes -= 128;
        c += 128;
        m += 128;
    }
}

inline void xote_generate_bytes(stream_ctx *x, uint8_t *c, uint32_t bytes)
{
    uint8_t output[128];
    int i;

    if (!bytes)
        return;
    for (;;)
    {
        xote(output, x->state);
        x->state[4] = x->state[4] + 2;
        if (!(x->state[4] >> 1))
        {
            x->state[5] = x->state[5] + 1;
        }
        if (bytes <= 128)
        {
            for (i = 0; i < bytes; ++i)
                c[i] = output[i];
            return;
        }
        for (i = 0; i < 128; ++i)
            c[i] = output[i];
        bytes -= 128;
        c += 128;
    }
}

void xote_decrypt_bytes(stream_ctx *x, const uint8_t *c, uint8_t *m, uint32_t bytes)
{
    xote_encrypt_bytes(x, c, m, bytes);
}

void xote_keystream_bytes(stream_ctx *x, uint8_t *stream, uint32_t bytes)
{
    uint32_t i;
    for (i = 0; i < bytes; ++i)
        stream[i] = 0;
    xote_encrypt_bytes(x, stream, stream, bytes);
}

void xote_prf(uint8_t *out, size_t outlen, const uint8_t key[KYBER_SYMBYTES], uint8_t * expnonce)
{
    stream_ctx ctx;
    xote_keysetup(&ctx, (uint8_t *)key);
    uint8_t iv[8] = { 0 };
    iv[0] = expnonce[0];
    xote_ivsetup(&ctx, iv);
    xote_keystream_bytes(&ctx, out, (uint32_t)outlen);
}

void xote_absorb(stream_ctx *ctx, const uint8_t *seed, uint8_t * expnonce)
{
    xote_keysetup(ctx, (uint8_t *)seed);
    uint8_t iv[8] = { 0 };
    iv[0] = expnonce[0];
    iv[1] = expnonce[1];

    xote_ivsetup(ctx, iv);
    xote_qr(ctx->state, ctx->state);
}

void xote_squeeze(uint8_t *out, size_t outbytes, stream_ctx *ctx)
{
    xote_generate_bytes(ctx, out, outbytes);
}

void xote_kdf(uint8_t *out, size_t outlen, uint8_t *in, size_t inlen)
{
    stream_ctx ctx = { 0x0 };
    uint32_t iv[2] = { 0x0 };
    size_t ctr = 0;

    while(inlen >= 32)
    {
        xote_keysetup_xor(&ctx, in);
        xote_ivsetup_xor(&ctx, (uint8_t *)iv);

        in += 32;
        inlen -= 32;

        iv[0]++;
        if(!iv[0])
            iv[1]++;
    }

    if(inlen)
    {
        uint8_t key_rem[32] = { 0x0 };
        for(int i = 0; i < inlen; i++)
            key_rem[i] = in[i];

        xote_keysetup_xor(&ctx, key_rem);
        xote_ivsetup_xor(&ctx, (uint8_t *)iv);
    }
 
    xote_generate_bytes(&ctx, out, outlen);   
}