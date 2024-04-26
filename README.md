# Projeto Kyber-Forró

## Utilizando Docker
```bash
docker build -f [DOCKERFILE PATH] -t [IMAGE NAME] [IMAGE PATH]
docker run -it -d --name [CONTAINER NAME] -v [HOST FOLDER PATH]:/app [IMAGE NAME]
docker exec -it [CONTAINER NAME] /bin/bash
```

## Compilando o projeto usando Makefile

### Testes de corretude
```bash
make PQCgenKAT_kem IMPLEMENTATION=[ALGORITHM] SEC_K=[SECURITY PARAMETER]
```

### Testes de performance
```bash
make test_speed IMPLEMENTATION=[ALGORITHM] SEC_K=[SECURITY PARAMETER]
```

### Parâmetros
`[ALGORITHM]`: AES, SHAKE, FORRO.
`[SECURITY PARAMETER]`: 2, 3 ou 4.