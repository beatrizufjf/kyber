#ifndef PRINT_SPEED_H
#define PRINT_SPEED_H

#include <stddef.h>
#include <stdint.h>

#define NTESTS 1000

typedef struct vector_time_str {
    uint64_t t_xof_absorb[NTESTS];
    uint64_t t_xof_squeeze[NTESTS];
    uint64_t t_prf[NTESTS];
    uint64_t t_kdf[NTESTS];
    uint64_t t_gen_a[NTESTS];
    uint64_t t_keypair[NTESTS];
    uint64_t t_encaps[NTESTS];
    uint64_t t_decaps[NTESTS];
} vector_time;

void print_results(const char *s, uint64_t *t, size_t tlen);
void print_results_with_csv(const char *s, uint64_t *t, size_t tlen, const char *filename);
void print_results_with_csv_str(const char *s, vector_time *vec_time, size_t tlen, const char *filename);

#endif
