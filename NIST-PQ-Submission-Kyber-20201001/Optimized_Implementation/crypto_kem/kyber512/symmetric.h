
#ifndef SYMMETRIC_H
#define SYMMETRIC_H

#include <stddef.h>
#include <stdint.h>
#include "params.h"

#ifdef KYBER_90S

#include "aes256ctr.h"
#include "sha2.h"

#if (KYBER_SSBYTES != 32)
#error "90s variant of Kyber can only generate keys of length 256 bits"
#endif

typedef aes256ctr_ctx xof_state;

#define kyber_aes256xof_absorb KYBER_NAMESPACE(_kyber_aes256xof_absorb)
void kyber_aes256xof_absorb(aes256ctr_ctx *state,
                            const uint8_t seed[KYBER_SYMBYTES],
                            uint8_t x,
                            uint8_t y);

#define kyber_aes256ctr_prf KYBER_NAMESPACE(_kyber_aes256ctr_prf)
void kyber_aes256ctr_prf(uint8_t *out,
                         size_t outlen,
                         const uint8_t key[KYBER_SYMBYTES],
                         uint8_t nonce);

#define XOF_BLOCKBYTES AES256CTR_BLOCKBYTES

#define hash_h(OUT, IN, INBYTES) sha256(OUT, IN, INBYTES)
#define hash_g(OUT, IN, INBYTES) sha512(OUT, IN, INBYTES)
#define xof_absorb(STATE, SEED, X, Y) \
        kyber_aes256xof_absorb(STATE, SEED, X, Y)
#define xof_squeezeblocks(OUT, OUTBLOCKS, STATE) \
        aes256ctr_squeezeblocks(OUT, OUTBLOCKS, STATE)
#define prf(OUT, OUTBYTES, KEY, NONCE) \
        kyber_aes256ctr_prf(OUT, OUTBYTES, KEY, NONCE)
#define kdf(OUT, IN, INBYTES) sha256(OUT, IN, INBYTES)

#elif KYBER_FORRO

#include "forro_cipher-main/src/forro/ref/forro.h"
#include "fips202.h"

typedef stream_ctx xof_state;
#define kyber_forroxof_absorb KYBER_NAMESPACE(_kyber_forroxof_absorb)
void kyber_forroxof_absorb(stream_ctx *state,
                        const uint8_t seed[KYBER_SYMBYTES],
                        uint8_t x,
                        uint8_t y);

#define kyber_forro_prf KYBER_NAMESPACE(_kyber_forro_prf)
void kyber_forro_prf(uint8_t *out,
                         size_t outlen,
                         const uint8_t key[KYBER_SYMBYTES],
                         uint8_t nonce);

#define XOF_BLOCKBYTES FORRO_SIZE_BLOCK

#define xof_absorb(STATE, SEED, X, Y) \
        kyber_forroxof_absorb(STATE, SEED, X, Y)
#define xof_squeezeblocks(OUT, OUTBLOCKS, STATE) \
        forro_squeeze(OUT, OUTBLOCKS * FORRO_SIZE_BLOCK, STATE)        

#define hash_h(OUT, IN, INBYTES) sha3_256(OUT, IN, INBYTES)
#define hash_g(OUT, IN, INBYTES) sha3_512(OUT, IN, INBYTES)
#define prf(OUT, OUTBYTES, KEY, NONCE) \
        kyber_forro_prf(OUT, OUTBYTES, KEY, NONCE)
#define kdf(OUT, IN, INBYTES) forro_kdf(OUT, KYBER_SSBYTES, IN, INBYTES)

#elif KYBER_XOTE

#include "forro_cipher-main/src/xote/ref/xote.h"
#include "fips202.h"

typedef stream_ctx xof_state;
#define kyber_xotexof_absorb KYBER_NAMESPACE(_kyber_xotexof_absorb)
void kyber_xotexof_absorb(stream_ctx *state,
                        const uint8_t seed[KYBER_SYMBYTES],
                        uint8_t x,
                        uint8_t y);

#define kyber_xote_prf KYBER_NAMESPACE(_kyber_xote_prf)
void kyber_xote_prf(uint8_t *out,
                         size_t outlen,
                         const uint8_t key[KYBER_SYMBYTES],
                         uint8_t nonce);

#define XOF_BLOCKBYTES XOTE_SIZE_BLOCK

#define xof_absorb(STATE, SEED, X, Y) \
        kyber_xotexof_absorb(STATE, SEED, X, Y)
#define xof_squeezeblocks(OUT, OUTBLOCKS, STATE) \
        xote_squeeze(OUT, OUTBLOCKS * XOTE_SIZE_BLOCK, STATE)        

#define hash_h(OUT, IN, INBYTES) sha3_256(OUT, IN, INBYTES)
#define hash_g(OUT, IN, INBYTES) sha3_512(OUT, IN, INBYTES)
#define prf(OUT, OUTBYTES, KEY, NONCE) \
        kyber_xote_prf(OUT, OUTBYTES, KEY, NONCE)
#define kdf(OUT, IN, INBYTES) xote_kdf(OUT, KYBER_SSBYTES, IN, INBYTES)

#else

#include "fips202.h"

typedef keccak_state xof_state;

#define kyber_shake128_absorb KYBER_NAMESPACE(_kyber_shake128_absorb)
void kyber_shake128_absorb(keccak_state *s,
                           const uint8_t seed[KYBER_SYMBYTES],
                           uint8_t x,
                           uint8_t y);

#define kyber_shake256_prf KYBER_NAMESPACE(_kyber_shake256_prf)
void kyber_shake256_prf(uint8_t *out,
                        size_t outlen,
                        const uint8_t key[KYBER_SYMBYTES],
                        uint8_t nonce);

#define XOF_BLOCKBYTES SHAKE128_RATE

#define hash_h(OUT, IN, INBYTES) sha3_256(OUT, IN, INBYTES)
#define hash_g(OUT, IN, INBYTES) sha3_512(OUT, IN, INBYTES)
#define xof_absorb(STATE, SEED, X, Y) kyber_shake128_absorb(STATE, SEED, X, Y)
#define xof_squeezeblocks(OUT, OUTBLOCKS, STATE) \
        shake128_squeezeblocks(OUT, OUTBLOCKS, STATE)
#define prf(OUT, OUTBYTES, KEY, NONCE) \
        kyber_shake256_prf(OUT, OUTBYTES, KEY, NONCE)
#define kdf(OUT, IN, INBYTES) shake256(OUT, KYBER_SSBYTES, IN, INBYTES)


#endif /* KYBER_90S */

#endif /* SYMMETRIC_H */

 
