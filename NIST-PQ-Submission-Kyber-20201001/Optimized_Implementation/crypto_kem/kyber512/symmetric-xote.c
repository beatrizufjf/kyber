#include <stddef.h>
#include <stdint.h>
#include "params.h"
#include "forro_cipher-main/src/xote/ref/xote.h"
#include "symmetric.h"

void kyber_xotexof_absorb(stream_ctx *state,
                            const uint8_t seed[KYBER_SYMBYTES],
                            uint8_t x, uint8_t y)
{
#if KYBER_SYMBYTES != 32
#error "Kyber-xote only supports KYBER_SYMBYTES = 32!"
#endif

  uint8_t expnonce[12] = {0};
  expnonce[0] = x;
  expnonce[1] = y;
  xote_absorb(state, seed, expnonce);
}

void kyber_xote_prf(uint8_t *out,
                         size_t outlen,
                         const uint8_t key[32],
                         uint8_t nonce)
{
  uint8_t expnonce[12] = {0};
  expnonce[0] = nonce;
  xote_prf(out, outlen, key, expnonce);
}
