#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cpucycles.h"
#include "speed_print.h"

static int cmp_uint64(const void *a, const void *b) {
  if(*(uint64_t *)a < *(uint64_t *)b) return -1;
  if(*(uint64_t *)a > *(uint64_t *)b) return 1;
  return 0;
}

static uint64_t median(uint64_t *l, size_t llen) {
  qsort(l,llen,sizeof(uint64_t),cmp_uint64);

  if(llen%2) return l[llen/2];
  else return (l[llen/2-1]+l[llen/2])/2;
}

static uint64_t average(uint64_t *t, size_t tlen) {
  size_t i;
  uint64_t acc=0;

  for(i=0;i<tlen;i++)
    acc += t[i];

  return acc/tlen;
}

void print_results(const char *s, uint64_t *t, size_t tlen) {
  size_t i;
  static uint64_t overhead = -1;

  if(tlen < 2) {
    fprintf(stderr, "ERROR: Need a least two cycle counts!\n");
    return;
  }

  if(overhead  == (uint64_t)-1)
    overhead = cpucycles_overhead();

  tlen--;
  for(i=0;i<tlen;++i)
    t[i] = t[i+1] - t[i] - overhead;

  printf("%s\n", s);
  printf("median: %llu cycles/ticks\n", (unsigned long long)median(t, tlen));
  printf("average: %llu cycles/ticks\n", (unsigned long long)average(t, tlen));
  printf("\n");
}

void print_results_with_csv(const char *s, uint64_t *t, size_t tlen, const char *filename) {
  size_t i;
  static uint64_t overhead = -1;
  char * filename_tmp = (char *)calloc(64, sizeof(char));
  memcpy(filename_tmp, filename, strlen(filename));

  if(tlen < 2) {
    fprintf(stderr, "ERROR: Need a least two cycle counts!\n");
    return;
  }

  if(overhead  == (uint64_t)-1)
    overhead = cpucycles_overhead();

  tlen--;
  // for(i=0;i<tlen;++i)
  //   t[i] = t[i+1] - t[i] - overhead;

  uint64_t u64_median = median(t, tlen);
  uint64_t u64_average = average(t, tlen);

  printf("%s\n", s);
  printf("median: %llu cycles/ticks\n", (unsigned long long)u64_median);
  printf("average: %llu cycles/ticks\n", (unsigned long long)u64_average);
  printf("\n");

  //Concatenate to form file name
  strcat(filename_tmp, s);
  size_t len = strlen(filename_tmp);
  filename_tmp[len-2] = 0x0;
  strcat(filename_tmp, ".csv");

  //Open file
  FILE *fpt;
  fpt = fopen(filename_tmp, "a+");
  // if (NULL != fpt) 
  // {
  //   fseek (fpt, 0, SEEK_END);
  //   size_t size = ftell(fpt);

  //   if (0 == size) {
  //       printf("File is empty, printing header...\n");
  //       fprintf(fpt, "median,average\n");
  //   }
  //   else 
  //   {
  //       printf("File is not empty, appending...\n");
  //   }
  // }
  // fprintf(fpt, "%llu,%llu\n", (unsigned long long)u64_median, (unsigned long long)u64_average);
  for(i=0;i<tlen-1;++i)
    fprintf(fpt, "%llu\n", (unsigned long long)t[i]);
  fclose(fpt);


  free(filename_tmp);
}

void print_results_with_csv_str(const char *s, vector_time *vec_time, size_t tlen, const char *filename) {
  size_t i;
  static uint64_t overhead = -1;
  char * filename_tmp = (char *)calloc(64, sizeof(char));
  memcpy(filename_tmp, filename, strlen(filename));

  if(tlen < 2) {
    fprintf(stderr, "ERROR: Need a least two cycle counts!\n");
    return;
  }

  // if(overhead  == (uint64_t)-1)
  //   overhead = cpucycles_overhead();

  // tlen--;
  // for(i=0;i<tlen;++i)
  //   t[i] = t[i+1] - t[i] - overhead;

  uint64_t u64_median_gen_a = median(vec_time->t_gen_a, tlen);
  uint64_t u64_average_gen_a = average(vec_time->t_gen_a, tlen);
  uint64_t u64_median_keypair = median(vec_time->t_keypair, tlen);
  uint64_t u64_average_keypair = average(vec_time->t_keypair, tlen);
  uint64_t u64_median_encaps = median(vec_time->t_encaps, tlen);
  uint64_t u64_average_encaps = average(vec_time->t_encaps, tlen);
  uint64_t u64_median_decaps = median(vec_time->t_decaps, tlen);
  uint64_t u64_average_decaps = average(vec_time->t_decaps, tlen);

  // printf("%s\n", s);
  printf("median: %llu cycles/ticks\n", (unsigned long long)u64_median_gen_a);
  printf("average: %llu cycles/ticks\n", (unsigned long long)u64_average_gen_a);
  printf("median: %llu cycles/ticks\n", (unsigned long long)u64_median_keypair);
  printf("average: %llu cycles/ticks\n", (unsigned long long)u64_average_keypair);
  printf("median: %llu cycles/ticks\n", (unsigned long long)u64_median_encaps);
  printf("average: %llu cycles/ticks\n", (unsigned long long)u64_average_encaps);
  printf("median: %llu cycles/ticks\n", (unsigned long long)u64_median_decaps);
  printf("average: %llu cycles/ticks\n", (unsigned long long)u64_average_decaps);
  printf("\n");

  //Concatenate to form file name
  // strcat(filename_tmp, s);
  // size_t len = strlen(filename_tmp);
  // filename_tmp[len-2] = 0x0;
  strcat(filename_tmp, ".csv");

  //Open file
  FILE *fpt;
  fpt = fopen(filename_tmp, "a+");
  if (NULL != fpt) 
  {
    fseek (fpt, 0, SEEK_END);
    size_t size = ftell(fpt);

    if (0 == size) {
        printf("File is empty, printing header...\n");
        fprintf(fpt, "gen_a,keypair,encaps,decaps\n");
    }
    else 
    {
        printf("File is not empty, appending...\n");
    }
  }
  // fprintf(fpt, "%llu,%llu\n", (unsigned long long)u64_median, (unsigned long long)u64_average);
  // for(i=10;i<tlen-10;++i)
  //   fprintf(fpt, "%llu,%llu,%llu,%llu\n", (unsigned long long)vec_time->t_gen_a[i], (unsigned long long)vec_time->t_keypair[i], (unsigned long long)vec_time->t_encaps[i], (unsigned long long)vec_time->t_decaps[i]);
  printf("Writing in file...\n");
  fprintf(fpt, "%llu,%llu,%llu,%llu\n", (unsigned long long)u64_median_gen_a, (unsigned long long)u64_median_keypair, (unsigned long long)u64_average_encaps, (unsigned long long)u64_average_decaps);
  printf("Closing file\n");
  fclose(fpt);

  free(filename_tmp);
}
