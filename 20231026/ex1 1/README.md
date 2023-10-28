# Atividade 26/10/2023 TDA I

[x] 2023102601. Criar um tipo abstrato de dados que represente uma pessoa, contendo: nome, data de nascimento e CPF.
- Crie uma função que receba um ponteiro para o TDA e preencha os dados da estrutura.
- Crie outra função que receba um ponteiro para o TDA e imprima os dados da estrutura.
- Crie um ponteiro para o TDA (no programa principal) e utilize as funções criadas.

[x] 2023102602. Para o exercício anterior crie um TDA para a data.
- Crie uma função que receba um ponteiro para o TDA e preencha os dados da estrutura.
- Crie outra função que receba um ponteiro para o TDA e imprima os dados da estrutura.
- Crie um ponteiro para o TDA (no programa principal) e utilize as funções criadas.

## Compilar (gcc)

No terminal executo seguinte comando para compilar o arquivo.
```shell
$ gcc -I src main.c src/person.c src/date.c -o output
```

## Compilar (Makefile)

| É necessário o `gcc` instalado e o `make` para utilizar o makefile (você não precisa se preocupar com isso se estiver em um sistema UNIX like).

No terminal executo seguinte comando para compilar o arquivo.
```shell
$ make
```
Após executar o comando o arquivo binário `output` deve ter sido gerado e você poder abrir ele para rodar o programa.