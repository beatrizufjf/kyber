#ifndef TEST_SPEED_H
#define TEST_SPEED_H

#define TOTAL_PRF_XOTE 0
#define TOTAL_PRF_SHAKE 1
#define TOTAL_KDF_XOTE 2
#define TOTAL_KDF_SHAKE 3
#define TOTAL_XOF_ABSORB_SHAKE 4
#define TOTAL_XOF_ABSORB_XOTE 5
#define TOTAL_XOF_SQUEEZE_SHAKE 6
#define TOTAL_XOF_SQUEEZE_XOTE 7


extern float tempo_total[];
extern int testes_ate_agora[];

char* nome_categoria(int categoria);
void registrar_resultado(float resultado, int qual_total);
void printar_media(int qual_total);

#endif