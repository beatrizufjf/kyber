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
#include <time.h>
#include <unistd.h>
#include "test_speed.h"

float tempo_total[8] = {-1, -1, -1, -1, -1, -1, -1, -1};
int testes_ate_agora[8] = {-1, -1, -1, -1, -1, -1, -1, -1};
char nomes_em_ordem[64][64] = {"TOTAL_PRF_XOTE", "TOTAL_PRF_SHAKE", "TOTAL_KDF_XOTE", "TOTAL_KDF_SHAKE", "TOTAL_XOF_ABSORB_SHAKE", "TOTAL_XOF_ABSORB_XOTE", "TOTAL_XOF_SQUEEZE_SHAKE", "TOTAL_XOF_SQUEEZE_XOTE"};

char* nome_categoria(int categoria) {
  return nomes_em_ordem[categoria];
}

void registrar_resultado(float resultado, int qual_total) {
    tempo_total[qual_total] += resultado;
    testes_ate_agora[qual_total]++;
}

void printar_media(int qual_total) {
  int testes = testes_ate_agora[qual_total];

  if (testes == -1) return;

  printf("Foram feitos um total de %d testes para %s, média foi de %f ms\n", 
    testes_ate_agora[qual_total], 
    nome_categoria(qual_total),
    (float) tempo_total[qual_total] / testes_ate_agora[qual_total]);
}

typedef uint64_t t[NTESTS];
// uint64_t t_gen_a[NTESTS], t_keypair[NTESTS];
uint64_t t_before, t_after;
uint8_t seed[KYBER_SYMBYTES] = {0};
int main()
{
  vector_time vec_time;
  unsigned int i;
  unsigned char pk[CRYPTO_PUBLICKEYBYTES] = {0};
  unsigned char sk[CRYPTO_SECRETKEYBYTES] = {0};
  unsigned char ct[CRYPTO_CIPHERTEXTBYTES] = {0};
  unsigned char key[CRYPTO_BYTES] = {0};
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
  sprintf(filename, "results/RESULTS_AES-K%d", KYBER_K);
  #elif KYBER_FORRO
  printf("Using Kyber with Forro\n");
  sprintf(filename, "results/RESULTS_FORRO-K%d", KYBER_K);
  #elif KYBER_XOTE
  printf("Using Kyber with Xote\n");
  sprintf(filename, "results/RESULTS_XOTE-K%d", KYBER_K);
  #else
  printf("Using Kyber with SHAKE\n");
  sprintf(filename, "results/RESULTS_SHAKE-K%d", KYBER_K);
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
    // t[i] = cpucycles();
    t_before = cpucycles();
    gen_matrix(matrix, seed, 0);
    t_after = cpucycles();
    // t[i] = t_after - t_before;
    vec_time.t_gen_a[i] = t_after - t_before;

    t_before = cpucycles();
    crypto_kem_keypair(pk, sk);
    t_after = cpucycles();
    vec_time.t_keypair[i] = t_after - t_before;

    t_before = cpucycles();
    crypto_kem_enc(ct, key, pk);
    t_after = cpucycles();
    vec_time.t_encaps[i] = t_after - t_before;

    t_before = cpucycles();
    crypto_kem_dec(key, ct, sk);
    t_after = cpucycles();
    vec_time.t_decaps[i] = t_after - t_before;
  }

  printar_media(TOTAL_PRF_XOTE);
  printar_media(TOTAL_KDF_XOTE);
  printar_media(TOTAL_PRF_SHAKE);
  printar_media(TOTAL_KDF_SHAKE);
  printar_media(TOTAL_XOF_ABSORB_SHAKE);
  printar_media(TOTAL_XOF_ABSORB_XOTE);
  printar_media(TOTAL_XOF_SQUEEZE_SHAKE);
  printar_media(TOTAL_XOF_SQUEEZE_XOTE);

  print_results_with_csv_str("gen_a: ", &vec_time, NTESTS, filename);
    



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
