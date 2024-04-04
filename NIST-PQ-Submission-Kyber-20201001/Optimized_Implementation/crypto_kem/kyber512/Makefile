CC=/usr/local/bin/gcc
CFLAGS += -O3 -march=native -fomit-frame-pointer
LDFLAGS=-lcrypto

# SOURCES= cbd.c fips202.c indcpa.c kem.c ntt.c poly.c polyvec.c PQCgenKAT_kem.c reduce.c rng.c verify.c symmetric-shake.c
# HEADERS= api.h cbd.h fips202.h indcpa.h ntt.h params.h poly.h polyvec.h reduce.h rng.h verify.h symmetric.h

FORRO_REF_SRC=forro_cipher-main/src/forro/ref/forro.c
FORRO_FLAGS=-march=native -mtune=native -O3 -fomit-frame-pointer -fwrapv

SOURCES_TEST= cbd.c fips202.c indcpa.c kem.c ntt.c poly.c polyvec.c test_speed.c reduce.c rng.c verify.c symmetric-shake.c sha256.c sha512.c aes256ctr.c symmetric-aes.c speed_print.c cpucycles.c
HEADERS_TEST= api.h cbd.h fips202.h indcpa.h ntt.h params.h poly.h polyvec.h reduce.h rng.h verify.h symmetric.h kem.h aes256ctr.h sha2.h speed_print.h cpucycles.h 

test_speed: $(HEADERS_TES) $(SOURCES_TEST)
	$(CC) $(FORRO_FLAGS) -o $@ $(SOURCES_TEST) $(LDFLAGS) $(FORRO_REF_SRC)

# PQCgenKAT_kem: $(HEADERS) $(SOURCES)
#	$(CC) $(CFLAGS) -o $@ $(SOURCES) $(LDFLAGS)


.PHONY: clean

clean:
	-rm test_speed
#	-rm PQCgenKAT_kem
