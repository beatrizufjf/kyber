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

### Script de performance
- Entre na pasta `/app/NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512`
- Execute o teste com `.\run_results.sh`.
    - Todos os testes serão compilados e executados automaticamente, variando `K` de 2 até 4 e passando por `AES`, `Forro` e `Shake`.
    - Cada teste será executado `N` vezes conforme setado dentro do script.

### Parâmetros
`[ALGORITHM]`: AES, SHAKE, FORRO.
`[SECURITY PARAMETER]`: 2, 3 ou 4.