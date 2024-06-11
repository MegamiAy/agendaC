# Documentação da Agenda

## Bibliotecas Usadas 

* `stdio.h` -> biblioteca padrão
* `stdlib.h` -> outra biblioteca padrão 
* `string.h` -> biblioteca de funções para manipulação de strings

## Prototipagem de Funções

* `int menu()` -> dá as opções de operação 
* `int add()` -> adiciona um novo contato
* `int consul()` -> faz uma pesquisa nos contatos
* `int rm()` -> remove um contato
* `int load()` -> carrega em tela, todos os contatos adicionados

## Definição dos tipos

`nome` & `telefone` como char, nome com limite e 50 e telefone com limite de 14

## Funções

funções criadas e puxadas em seus devidos locais

## Função Principal

`Main` - Como principal, onde o menu é chamado e por sua vez, é onde tudo ocorre

## Funções do CANSI

* `fopen()` -> abre um arquivo
* `fwrite()` -> escreve em um arquivo
* `fread()` -> lê o arquivo
* `fclose()` -> fecha o arquivo
* `sizeof()` -> determina tamanho do dado/aloca memória
* `strcmp()` -> compara duas strings

### Formas de abrir arquivos

* `fopen("contatos.txt", "a")` -> adiciona dados do arquivo
* `fopen("contatos.bin", "ab")` -> adiciona dados do arquivo binário
* `fopen("contatos.txt", "w")` -> subscreve dados do arquivo
* `fopen("contatos.bin", "wb")` -> subscreve dados do arquivo binário
* `fopen("contatos.txt", "r")` -> lê dados do arquivo
* `fopen("contatos.bin", "rb")` ->  lê dados do arquivo binário