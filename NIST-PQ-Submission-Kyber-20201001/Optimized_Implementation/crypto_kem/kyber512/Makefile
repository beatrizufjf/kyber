
#CC=/usr/local/bin/gcc
#CFLAGS += -O3 -march=native -fomit-frame-pointer
#LDFLAGS=-lcrypto

#SOURCES= cbd.c fips202.c indcpa.c kem.c ntt.c poly.c polyvec.c PQCgenKAT_kem.c reduce.c rng.c verify.c symmetric-shake.c forro_cipher-main/src/forro/ref/forro.c
#HEADERS= api.h cbd.h fips202.h indcpa.h ntt.h params.h poly.h polyvec.h reduce.h rng.h verify.h symmetric.h forro_cipher-main/src/forro/ref/forro.h

# 		FORRO_REF_SRC=forro_cipher-main/src/forro/ref/forro.c
# 		FORRO_FLAGS=-march=native -mtune=native -O3 -fomit-frame-pointer -fwrapv

#SOURCES_TEST= cbd.c fips202.c indcpa.c kem.c ntt.c poly.c polyvec.c test_speed.c reduce.c rng.c verify.c symmetric-shake.c sha256.c sha512.c aes256ctr.c symmetric-aes.c speed_print.c cpucycles.c forro_cipher-main/src/forro/ref/forro.c
#HEADERS_TEST= api.h cbd.h fips202.h indcpa.h ntt.h params.h poly.h polyvec.h reduce.h rng.h verify.h symmetric.h kem.h aes256ctr.h sha2.h speed_print.h cpucycles.h forro_cipher-main/src/forro/ref/forro.h



#test_speed: $(HEADERS_TES) $(SOURCES_TEST)
#	$(CC) -o $@ $(SOURCES_TEST) $(LDFLAGS)

#PQCgenKAT_kem: $(HEADERS) $(SOURCES)
#	$(CC) $(CFLAGS) -o $@ $(SOURCES) $(LDFLAGS)


#.PHONY: clean

#clean:
#	-rm test_speed
#	-rm PQCgenKAT_kem


CC = /usr/bin/gcc
CFLAGS += -O3 -march=native -fomit-frame-pointer
LDFLAGS = -lcrypto

# Diretório do código-fonte
SRC_DIR = src

# Arquivos de código-fonte comuns
COMMON_SOURCES = $(wildcard $(SRC_DIR)/*.c)
COMMON_HEADERS = $(wildcard $(SRC_DIR)/*.h)

# Arquivo de teste
SOURCES= cbd.c fips202.c indcpa.c kem.c ntt.c poly.c polyvec.c PQCgenKAT_kem.c reduce.c rng.c verify.c symmetric-shake.c sha256.c sha512.c aes256ctr.c symmetric-aes.c symmetric-forro.c symmetric-xote.c forro_cipher-main/src/forro/ref/forro.c forro_cipher-main/src/xote/ref/xote.c
HEADERS= api.h cbd.h fips202.h indcpa.h ntt.h params.h poly.h polyvec.h reduce.h rng.h verify.h symmetric.h aes256ctr.h sha2.h forro_cipher-main/src/forro/ref/forro.h forro_cipher-main/src/xote/ref/xote.c

TEST_SOURCE = cbd.c fips202.c indcpa.c kem.c ntt.c poly.c polyvec.c test_speed.c reduce.c rng.c verify.c symmetric-shake.c sha256.c sha512.c aes256ctr.c symmetric-aes.c speed_print.c cpucycles.c symmetric-forro.c symmetric-xote.c forro_cipher-main/src/forro/ref/forro.c forro_cipher-main/src/xote/ref/xote.c
TEST_HEADER = api.h cbd.h fips202.h indcpa.h ntt.h params.h poly.h polyvec.h reduce.h rng.h verify.h symmetric.h kem.h aes256ctr.h sha2.h speed_print.h cpucycles.h forro_cipher-main/src/forro/ref/forro.h forro_cipher-main/src/xote/ref/xote.h

TEST_PRIMITIVES_SOURCE = cbd.c fips202.c indcpa.c kem.c ntt.c poly.c polyvec.c test_speed_primitives.c reduce.c rng.c verify.c symmetric-shake.c sha256.c sha512.c aes256ctr.c symmetric-aes.c speed_print.c cpucycles.c symmetric-forro.c symmetric-xote.c forro_cipher-main/src/forro/ref/forro.c forro_cipher-main/src/xote/ref/xote.c
TEST_PRIMITIVES_HEADER = api.h cbd.h fips202.h indcpa.h ntt.h params.h poly.h polyvec.h reduce.h rng.h verify.h symmetric.h kem.h aes256ctr.h sha2.h speed_print.h cpucycles.h forro_cipher-main/src/forro/ref/forro.h forro_cipher-main/src/xote/ref/xote.h


# Executável de teste
TEST_SPEED = test_speed
TEST_SPEED_PRIMITIVES = test_speed_primitives

# Flags para cada implementação
SHAKE_FLAGS = -DKYBER_SHAKE
AES_FLAGS = -DKYBER_90S
FORRO_FLAGS = -DKYBER_FORRO
XOTE_FLAGS = -DKYBER_XOTE

SEC_K2_FLAGS = -DKYBER_K=2
SEC_K3_FLAGS = -DKYBER_K=3
SEC_K4_FLAGS = -DKYBER_K=4

# Implementação padrão
IMPLEMENTATION ?= SHAKE
SEC_K ?= 2

ifeq ($(IMPLEMENTATION), SHAKE)
    CFLAGS += $(SHAKE_FLAGS)
endif
ifeq ($(IMPLEMENTATION), AES)
    CFLAGS += $(AES_FLAGS)
endif
ifeq ($(IMPLEMENTATION), FORRO)
    CFLAGS += $(FORRO_FLAGS)
endif
ifeq ($(IMPLEMENTATION), XOTE)
    CFLAGS += $(XOTE_FLAGS)
endif

ifeq ($(SEC_K), 2)
	CFLAGS += $(SEC_K2_FLAGS)
endif
ifeq ($(SEC_K), 3)
	CFLAGS += $(SEC_K3_FLAGS)
endif
ifeq ($(SEC_K), 4)
	CFLAGS += $(SEC_K4_FLAGS)
endif

# Regra de compilação
PQCgenKAT_kem: $(HEADERS) $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $(SOURCES) $(LDFLAGS)

test_speed: $(TEST_SPEED)

$(TEST_SPEED): $(COMMON_SOURCES) $(COMMON_HEADERS) $(TEST_SOURCE) $(TEST_HEADER)
	$(CC) $(CFLAGS) -o $@ $(COMMON_SOURCES) $(TEST_SOURCE) $(LDFLAGS)

test_speed_primitives: $(TEST_SPEED_PRIMITIVES)

$(TEST_SPEED_PRIMITIVES): $(COMMON_SOURCES) $(COMMON_HEADERS) $(TEST_PRIMITIVES_SOURCE) $(TEST_PRIMITIVES_HEADER)
	$(CC) $(CFLAGS) -o $@ $(COMMON_SOURCES) $(TEST_PRIMITIVES_SOURCE) $(LDFLAGS)

# Regra de limpeza
clean:
	-rm -f $(TEST_SPEED)
	-rm -f $(TEST_SPEED_PRIMITIVES)
	-rm -f PQCgenKAT_kem
