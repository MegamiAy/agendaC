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

`nome` & `fone` dentro de um struct, como string (char), nome com limite e 50 e fone com limite de 14

### typedof struct (Estrutura de novo tipo)
```
typedef struct{
    char nome[50];
    char fone[14];
} Contato;
```
* `typedef` -> define novo tipo de dado
* `struct` -> define uma estrutura com variáveis

## Funções

funções criadas e puxadas em seus devidos locais

## Função Principal

`Main` - Como principal, onde o menu é chamado e por sua vez, é onde tudo ocorre

<!-- Essas coisas não fazem parte de uma documentação, coloque no docs "Docs de Cola, Geral" -->
<!-- :P não tenho acesso, paia -->

## Estrutura Final
```
> bibliotecas

> struct definição dos tipos

> prototipagem de funções
    > identificação delas... dizendo que elas existem

> setando a coleção de dados = Contatos
> setando a variável de opções

> primeira função,
    > responsável por criar o menu e chamar as outras funções

> segunda função,
    > responsável por adicionar um contato

> terceia função,
    > responsável por fazer uma consulta nos contatos existentes

> quarta função,
    > responsável por listar todo o banco de contatos registrados e ativos

> quinta função,
    > responsável por deletar um contato específico

> sexta função,
    > responsável por puxar o menu, é o ponto de entrada do programa

```


<!-- ## Funções do CANSI 

* `fopen()` -> abre um arquivo 
* `fwrite()` -> escreve em um arquivo (bin)
* `fprintf` -> imprime (escreve) em um arquivo (txt)
* `fread()` -> lê o arquivo (bin)
* `fscanf()` -> lê dados formatados em um arquivo (txt)
* `fclose()` -> fecha o arquivo
* `sizeof()` -> determina tamanho do dado/aloca memória
* `strcmp()` -> compara duas strings

### Formas de abrir arquivos

* `fopen("contatos.txt", "a")` -> adiciona dados do arquivo
* `fopen("contatos.bin", "ab")` -> adiciona dados do arquivo binário
* `fopen("contatos.txt", "w")` -> subscreve dados do arquivo
* `fopen("contatos.bin", "wb")` -> subscreve dados do arquivo binário
* `fopen("contatos.txt", "r")` -> lê dados do arquivo
* `fopen("contatos.bin", "rb")` -> lê dados do arquivo binário

### Manipulação do FILE *arquivo

`FILE` é uma função da biblioteca C que trabalha com arquivos<br>
`FILE *` aponta para um arquivo específico, definido pelo usuário<br>

```
FILE *arquivo;
arquivo = fopen("meuArquivo.bin","rb");
```

No exemplo acima, `arquivo` aponta para a seguinte declaração `fopen("meuArquivo.bin","rb")`, <br>
com isto, o arquivo `meuArquivo` definido por `arquivo` é aberto. -->
