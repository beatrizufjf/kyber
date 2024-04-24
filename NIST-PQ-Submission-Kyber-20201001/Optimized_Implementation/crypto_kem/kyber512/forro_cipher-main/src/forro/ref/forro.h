#include <stdint.h>
#include <time.h>
#include "../../../../params.h"

#ifndef __basic_def
#define __basic_def
// Little endian machine assumed (x86-64).
#define U32TO8_LITTLE(p, v) (((uint32_t *)(p))[0] = v)
#define U8TO32_LITTLE(p) (((uint32_t *)(p))[0])

#define FORRO_SIZE_BLOCK 64 //bytes

static const uint8_t SIGMA[16] = "voltadaasabranca";
typedef struct
{
  uint32_t state[16];
} stream_ctx __attribute__((aligned(16)));
#endif

void forro(uint8_t out[64], const uint32_t init[16]);
void forro_qr(uint32_t state_vector[16]);
void forro_init();
void forro_keysetup(stream_ctx *x, uint8_t *key);
void forro_ivsetup(stream_ctx *x, uint8_t *iv);
void forro_encrypt_bytes(stream_ctx *x, const uint8_t *m, uint8_t *c, uint32_t bytes);
void forro_decrypt_bytes(stream_ctx *x, const uint8_t *c, uint8_t *m, uint32_t bytes);
void forro_keystream_bytes(stream_ctx *x, uint8_t *stream, uint32_t bytes);

void forro_prf(uint8_t *out, size_t outlen, const uint8_t key[KYBER_SYMBYTES], uint8_t * expnonce);
void forro_absorb(stream_ctx *ctx, const uint8_t *seed, uint8_t * expnonce);
void forro_squeeze(uint8_t *out, size_t nblocks, stream_ctx *ctx);