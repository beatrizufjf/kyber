#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "api.h"
// #include "kex.h"  //é um arquivo que deveria estar aqui dentro dessa pasta, para eu conseguir puxar ele dentro desse código
#include "params.h"
#include "indcpa.h"
#include "poly.h"
#include "polyvec.h"
#include "cpucycles.h"
#include "speed_print.h"
#include "symmetric.h"
#include <time.h>
#include <unistd.h>
#include <sys/random.h>

#define GEN_MATRIX_NBLOCKS ((12*KYBER_N/8*(1 << 12)/KYBER_Q \
                             + XOF_BLOCKBYTES)/XOF_BLOCKBYTES)

typedef

uint64_t t[NTESTS];
// uint64_t t_gen_a[NTESTS], t_keypair[NTESTS];
uint64_t t_before, t_after;
int main()
{
  vector_time_primitives vec_time;
  int rv;
  unsigned int i;
  xof_state state = { 0x0 };
  unsigned char key[CRYPTO_BYTES] = {0};
  unsigned int idx_i, idx_j;
  uint8_t buf_xof[GEN_MATRIX_NBLOCKS*XOF_BLOCKBYTES+2] = { 0x0 };
  uint8_t buf[KYBER_ETA1 * KYBER_N / 4];
  size_t size_buf = sizeof(buf);
  uint8_t seed[KYBER_SYMBYTES];
  uint8_t nonce;
  unsigned char kr[2*KYBER_SYMBYTES] = {0};
 //  unsigned char kexsenda[KEX_AKE_SENDABYTES] = {0};
 //  unsigned char kexsendb[KEX_AKE_SENDBBYTES] = {0};
 //  unsigned char kexkey[KEX_SSBYTES] = {0};
  polyvec matrix[KYBER_K];
  poly ap;

  char * filename = (char *)calloc(64, sizeof(char));

  printf("\n\n ------ Parameters ------ \n\n");
  printf("Using KYBER_K = %d\n", KYBER_K);
  #ifdef KYBER_90S
  printf("Using Kyber with AES\n");
  sprintf(filename, "results/RESULTS_PRIMITIVES_AES-K%d", KYBER_K);
  #elif KYBER_FORRO
  printf("Using Kyber with Forro\n");
  sprintf(filename, "results/RESULTS_PRIMITIVES_FORRO-K%d", KYBER_K);
  #elif KYBER_XOTE
  printf("Using Kyber with Xote\n");
  sprintf(filename, "results/RESULTS_PRIMITIVES_XOTE-K%d", KYBER_K);
  #else
  printf("Using Kyber with SHAKE\n");
  sprintf(filename, "results/RESULTS_PRIMITIVES_SHAKE-K%d", KYBER_K);
  #endif
  printf("\n ------------------------- \n\n");

  // for(i=0;i<NTESTS;i++) {
  //   // t[i] = cpucycles();
  //   t_before = cpucycles();
  //   gen_matrix(matrix, seed, 0);
  //   t_after = cpucycles();
  //   t_gen_a[i] = t_after - t_before;
  // }
  //   print_results_with_csv("gen_a: ", t, NTESTS, filename);

  // for(i=0;i<NTESTS;i++) {
  //   t[i] = cpucycles();
  //   poly_getnoise_eta1(&ap, seed, 0);
  // }
  //   print_results("poly_getnoise_eta1: ", t, NTESTS);

  // for(i=0;i<NTESTS;i++) {
  //   t[i] = cpucycles();
  //   poly_getnoise_eta2(&ap, seed, 0);
  // }
  //   print_results("poly_getnoise_eta2: ", t, NTESTS);

  // for(i=0;i<NTESTS;i++) {
  //   t[i] = cpucycles();
  //   poly_ntt(&ap);
  // }
  //   print_results("NTT: ", t, NTESTS);

  // for(i=0;i<NTESTS;i++) {
  //   t[i] = cpucycles();
  //   poly_invntt_tomont(&ap);
  // }
  //   print_results("INVNTT: ", t, NTESTS);

  // for(i=0;i<NTESTS;i++) {
  //   t[i] = cpucycles();
  //   crypto_kem_keypair(pk, sk);
  // }
  //   print_results_with_csv("kyber_keypair: ", t, NTESTS, filename);

  // for(i=0;i<NTESTS;i++) {
  //   t[i] = cpucycles();
  //   crypto_kem_enc(ct, key, pk);
  // }
  //   print_results_with_csv("kyber_encaps: ", t, NTESTS, filename);

  // for(i=0;i<NTESTS;i++) {
  //   t[i] = cpucycles();
  //   crypto_kem_dec(key, ct, sk);
  // }
  //   print_results_with_csv("kyber_decaps: ", t, NTESTS, filename);


  for(i=0;i<NTESTS;i++) {

    rv = getrandom(seed, KYBER_SYMBYTES, 0);
    rv = getrandom(&idx_i, 4, 0);
    rv = getrandom(&idx_j, 4, 0);
    idx_i = idx_i % KYBER_K;
    idx_j = idx_j % KYBER_K;
    t_before = cpucycles();
    xof_absorb(&state, seed, idx_i, idx_j);
    t_after = cpucycles();
    vec_time.t_xof_absorb[i] = t_after - t_before;

    t_before = cpucycles();
    xof_squeezeblocks(buf_xof, GEN_MATRIX_NBLOCKS, &state);
    t_after = cpucycles();
    vec_time.t_xof_squeeze[i] = t_after - t_before;

    rv = getrandom(seed, KYBER_SYMBYTES, 0);
    rv = getrandom(&nonce, 1, 0);
    t_before = cpucycles();
    prf(buf, size_buf, seed, nonce);
    t_after = cpucycles();
    vec_time.t_prf[i] = t_after - t_before;

    rv = getrandom(kr, 2*KYBER_SYMBYTES, 0);
    t_before = cpucycles();
    kdf(key, kr, 2*KYBER_SYMBYTES);
    t_after = cpucycles();
    vec_time.t_kdf[i] = t_after - t_before;
  }
    print_results_primitives_with_csv_str("primitives: ", &vec_time, NTESTS, filename);


/* 
  for(i=0;i<NTESTS;i++) {
    t[i] = cpucycles();
    kex_uake_initA(kexsenda, key, sk, pk);
  }
  print_results("kex_uake_initA: ", t, NTESTS);

  for(i=0;i<NTESTS;i++) {
    t[i] = cpucycles();
    kex_uake_sharedB(kexsendb, kexkey, kexsenda, sk);
  }
  print_results("kex_uake_sharedB: ", t, NTESTS);

  for(i=0;i<NTESTS;i++) {
    t[i] = cpucycles();
    kex_uake_sharedA(kexkey, kexsendb, key, sk);
  }
  print_results("kex_uake_sharedA: ", t, NTESTS);

  for(i=0;i<NTESTS;i++) {
    t[i] = cpucycles();
    kex_ake_initA(kexsenda, key, sk, pk);
  }
  print_results("kex_ake_initA: ", t, NTESTS);

  for(i=0;i<NTESTS;i++) {
    t[i] = cpucycles();
    kex_ake_sharedB(kexsendb, kexkey, kexsenda, sk, pk);
  }
  print_results("kex_ake_sharedB: ", t, NTESTS);

  for(i=0;i<NTESTS;i++) {
    t[i] = cpucycles();
    kex_ake_sharedA(kexkey, kexsendb, key, sk, sk);
  }
  print_results("kex_ake_sharedA: ", t, NTESTS);
*/

  free(filename);
  return 0;
}