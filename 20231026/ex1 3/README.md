# Atividade 26/10/2023 TDA II (2023102604)

Desenvolva um TAD que represente um número complexo z = x + iy, em que i² = –1, sendo x a sua parte real e y a parte imaginária. O TAD deverá conter as seguintes funções:
- criar um número complexo;
- destruir um número complexo;
- soma de dois números complexos;
- subtração de dois números complexos;
- multiplicação de dois números complexos;
- divisão de dois números complexos.

## Compilar (gcc)

No terminal executo seguinte comando para compilar o arquivo.
```shell
$ gcc -I src main.c src/complex.c -o output
```

## Compilar (Makefile)

| É necessário o `gcc` instalado e o `make` para utilizar o makefile (você não precisa se preocupar com isso se estiver em um sistema UNIX like).

No terminal executo seguinte comando para compilar o arquivo.
```shell
$ make
```
Após executar o comando o arquivo binário `output` deve ter sido gerado e você poder abrir ele para rodar o programa.