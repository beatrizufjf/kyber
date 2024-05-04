#include <stdint.h>
#include <time.h>
#include "../../../../params.h"

#ifndef __basic_def
#define __basic_def
// Little endian machine assumed (x86-64).
#define U32TO8_LITTLE(p, v) (((uint32_t *)(p))[0] = v)
#define U8TO32_LITTLE(p) (((uint32_t *)(p))[0])

#define XOTE_SIZE_BLOCK 128 //bytes

static const uint8_t SIGMA[16] = "voltadaasabranca";
typedef struct
{
  uint32_t state[16];
} stream_ctx __attribute__((aligned(16)));
#endif

void xote(uint8_t out[128], const uint32_t init[16]);
void xote_qr(uint32_t state_vector[16], uint32_t state_vector2[16]);
void xote_init();
void xote_keysetup(stream_ctx *x, uint8_t *key);
void xote_ivsetup(stream_ctx *x, uint8_t *iv);
void xote_encrypt_bytes(stream_ctx *x, const uint8_t *m, uint8_t *c, uint32_t bytes);
void xote_decrypt_bytes(stream_ctx *x, const uint8_t *c, uint8_t *m, uint32_t bytes);
void xote_keystream_bytes(stream_ctx *x, uint8_t *stream, uint32_t bytes);
void xote_generate_bytes(stream_ctx *x, uint8_t *c, uint32_t bytes);

void xote_prf(uint8_t *out, size_t outlen, const uint8_t key[KYBER_SYMBYTES], uint8_t * expnonce);
void xote_absorb(stream_ctx *ctx, const uint8_t *seed, uint8_t * expnonce);
void xote_squeeze(uint8_t *out, size_t nblocks, stream_ctx *ctx);
void xote_kdf(uint8_t *out, size_t outlen, uint8_t *in, size_t inlen);