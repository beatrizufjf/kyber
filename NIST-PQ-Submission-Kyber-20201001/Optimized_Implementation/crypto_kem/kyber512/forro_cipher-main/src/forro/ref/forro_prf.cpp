#include "forro.h"


void forro_prf(uint8_t *out, size_t outlen, const uint8_t key[KYBER_SYMBYTES], uint8_t nonce)
{
    stream_ctx ctx = {0};
    forro_keysetup(&ctx, &key);
    // forro_keysetup(stream_ctx *x, uint8_t *key);
    uint8_t iv[16] = { 0 };
    iv[0] = nonce;
    forro_ivsetup(&ctx, iv);
    // forro_ivsetup(stream_ctx *x, uint8_t *iv);
    forro_keystream_bytes(&ctx, out, (uint32_t)outlen);
}