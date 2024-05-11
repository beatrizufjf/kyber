#include <stddef.h>
#include <stdint.h>
#include "params.h"
#include "forro_cipher-main/src/xote/ref/xote.h"
#include "symmetric.h"
#include <stdio.h>
#include "test_speed.h"
#include <time.h>

void kyber_xotexof_absorb(stream_ctx *state,
                            const uint8_t seed[KYBER_SYMBYTES],
                            uint8_t x, uint8_t y)
{
#if KYBER_SYMBYTES != 32
#error "Kyber-xote only supports KYBER_SYMBYTES = 32!"
#endif
  int inicio = clock();
  uint8_t expnonce[12] = {0};
  expnonce[0] = x;
  expnonce[1] = y;
  xote_absorb(state, seed, expnonce);
  int intervalo = clock() - inicio;
  float tempo_ms = (float)intervalo/CLOCKS_PER_SEC *1000;
  registrar_resultado(tempo_ms, TOTAL_XOF_ABSORB_XOTE);
}

void kyber_xote_prf(uint8_t *out,
                         size_t outlen,
                         const uint8_t key[32],
                         uint8_t nonce)
{
  uint8_t expnonce[12] = {0};
  expnonce[0] = nonce;
  // int inicio = clock();
  xote_prf(out, outlen, key, expnonce);
  // int intervalo = clock() - inicio;
  // float tempo_ms = (float)intervalo/CLOCKS_PER_SEC *1000;
  // registrar_resultado(tempo_ms, TOTAL_PRF_XOTE);
  //printf("tempo xote_PRF: %f\n", soma_prf/(float)cont);
  
}
