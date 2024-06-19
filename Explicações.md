## Revisando o trabalho e explicando, p/ gente conseguir apresentar

### O que o programa faz?
1. **Adicionar Contato:** Você pode adicionar nomes e telefones de pessoas;
2. **Pesquisar Contato:** Você pode procurar por um nome na lista para ver o telefone da pessoa;
3. **Remover Contato:** Se quiser, pode apagar um contato da lista;
4. **Carregar Todos:** Mostra todos os contatos que estão na lista;
5. **Sair:** Fecha o programa quando você não quiser usar mais.

### Como o programa funciona?
1. **Add:** Para adicionar você deve inserir o nome e o telefone da pessoa. O programa ira guardar as informações;
2. **Consul:** Para pesquisar você deve inserir o nome da pessoa e o programa te mostra o telefone;
3. **Rm:** Para remover, primeiro deve pesquisar para saber se o contato realmente existe, depois confirmar que quer excluir;
4. **Load:** Mostra o nome e o telefone de todos os contatos adicionados;
5. **Sair:** Não existe uma função específica para sair, o programa apenas se encerra quando o número 5 é digitado.

### Coisas importantes
1. O programa grava as informações em um arquivo binário chamdo de `contatos.bin`;
2. O máximo de caractéres no nome de um contato é 50, e o telefone tem um máximo de 14.

#

### Bibliotecas
Dizem ao computador como lidar com diferentes partes do programa, por exemplo:
- `stdio.h` é usada para ler e escrever coisas na tela -> `scanf()` & `printf()`;
- `stdlib.h` ajuda a lidar com a memória do computador -> ;
- `string.h` ajuda a trabalhar com textos -> ;

### Sctruct
É usado para definir um novo tipo de dados que combina vários tipos diferentes em uma única estrutura; <br>
    - `typedef`: indica que estamos definindo um novo tipo.
    - `struct {}`: define a estrutura de dados, que neste caso contém dois membros: nome (uma string de até 50 caracteres) e fone (uma string de até 14 caracteres).
    - `Contato`: nome do novo tipo que estamos definindo usando typedef.

### Prototipagem
É onde se declara para o programa que vão existir/ser usadas cinco funções diferentes.

### Variável global
Onde deixa definido variáveis que vão ser usadas em diversas partes do programa
- `contato` vai guardar as informações de um único contato por ver(nome e telefone);
- `op` vai guardar a/as opções(do menu) escolhidas pelo usuário.

### Menu de ações
Mostra o menu na tela, com todas as opções do programa. <br>
Dependendo da função que a pessoa escolher, o programa vai chamar uma função diferente, dentro das existentes, e realizar a ação delas.

### Adicionar Contato
Permite adicionar um contato ao arquivi `contatos.bin`.
1. Primeiro a função abre o arquivo, usando:
```
    FILE *fptr;
    fptr = fopen("contatos.bin", "ab");
```
2. Caso não consiga abrir o arquivo, mostra uma mensagem de erro:
```
    if (fptr == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return 1;
    }
```
3. Depos pede para que você/usuário digite o nome e o telefone de quem deseja adicionar:
```
    printf("Nome do Contato: ");
    scanf("%s", contato.nome);
    fflush(stdin);

    printf("Telefone: ");
    scanf("%s", contato.fone);
    fflush(stdin);
```
4. Por fim, insere as informações no arquivo e fecha ele:
```
    fwrite(&contato, sizeof(Contato), 1, fptr);
    fclose(fptr);
```

### Consultar Contato
Permite consultar um contato existente no arquivo `contatos.bin`.
1. Primeiro a função pede que você digite o nome da pessoa que quer encontrar:
```
    printf("Nome do contato para pesquisar: ");
    scanf("%s", n_pesq);
```
2. Então abre o arquivo para ler (`rb`). Mas caso não consiga abrir, mostra uma mensagem de erro:
```
    if ((fptr = fopen("contatos.bin", "rb")) == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return 1;
    }
```
3. Depois de abrir, ele lê o arquivo procurando pelo nome digitado:
```
    while (fread(&contato, sizeof(Contato), 1, fptr)) {
        if (strcmp(contato.nome, n_pesq) == 0) {
            printf("Nome: %s\nTelefone: %s\n\n", contato.nome, contato.fone);
            c_existe = 1;
            break;
        }
    }
```
4. Se encontra o contato, mostra o nome e telefone. Se não encontra, mostra que o contato não existe:
```
    if dentro do while = caso ache o contato

        if (strcmp(contato.nome, n_pesq) == 0) {
            printf("Nome: %s\nTelefone: %s\n\n", contato.nome, contato.fone);
            c_existe = 1;
            break;
        }

    if fora do while = caso não ache o contato

    if (c_existe == 0) {
        printf("Contato nao existe...\n");
    }

```
5. Fecha o arquivo e finaliza a consulta
```
    fclose(fptr);
    return 0;
```

### Remover Contato
Permite remover um contato se ele existir no arquivo `contatos.bin`.
1. Primeiro a função pede que você digite o nome da pessoa que quer remover:
```
    printf("Nome do contato que deseja remover: ");
    scanf("%s", n_pesq);
```
2. Abre o arquivo original para ler(`rb`). Se não abre, mostra uma mensagem de erro:
```
    if ((fptr = fopen("contatos.bin", "rb")) == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return 1;
    }
```
3. Cria um arquivo temporário chamado de `temp.bin` para escrever (`wb`), mas caso não consiga, da um erro:
```
    temp = fopen("temp.bin", "wb");
    if (temp == NULL) {
        printf("Erro ao criar arquivo temporário!\n");
        fclose(fptr);
        return 1;
    }
```
4. Enquanto ele esta lendo o arquivo original `contatos.bin`, ele verifica se o nome de algum contato existente  é igual ao digitado:
```
    while (fread(&contato, sizeof(Contato), 1, fptr)) {
         if (strcmp(contato.nome, n_pesq) == 0) {
                printf("Contato encontrado:\n");
                printf("Nome: %s\nTelefone: %s\n", contato.nome, contato.fone);
                c_existe = 1;
         ......
    }
    if (!c_existe) {
            printf("Contato não encontrado.\n");
    }

```
5. Se ele encontra o contato, pergunta se você realmente quer deletar ele:
```
    isso ainda dentro do while

    int opR = 0;
    printf("Deseja realmente remover este contato?\n1. Sim\n2. Não\n");
    scanf("%i", &opR);
```
6. Recebe a resposta da pergunta anterior e armazena na varíavel `opR`, então deleta ou não o contato;
   - Se não quiser, cancela a ação e escreve o contato no arquivo temporário
   - Se quiser, remove o contato do arquivo original e renomeia o arquivo temporario para `contatos.bin` 
```
    switch (opR) {
              case 1:
                  // Remover o contato
                  break;
              case 2:
                  printf("\nAção cancelada.\n");
                  fwrite(&contato, sizeof(Contato), 1, temp);
                  break;
              default:
                  printf("\nOpção inválida.\n");
                  break;
    }
```
```
      } else {
          fwrite(&contato, sizeof(Contato), 1, temp);
      }

    fora do while

    fclose(fptr);
    fclose(temp);
    remove("contatos.bin");
    rename("temp.bin", "contatos.bin");

```

### Carregar Todos os Contatos
Permite carregar todos os contatos que existem no arquivo `contatos.bin`.
1. Primeiro a função abre o arquivo para ler (`rb`), se não abre, mostra o erro:
```
    fptr = fopen("contatos.bin", "rb");
    if (fptr == NULL) {
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }
```
2. Depois, lê o arquivo mostrando todos os nomes e números que estão guardados... e fecha o arquivo:
```
    printf("\n=========\nContatos: \n\n");  
        while (fread(&contato, sizeof(Contato), 1, fptr)) {    
            printf("Nome: %s \nNumero: %s \n\n", contato.nome, contato.fone);
        }
        fclose(fptr);
        return 0;
    }
```

### Função principal
É onde o programa começa a ser executado quando você inicia ele; <br>
É onde o menu fica em loop, até ser encerrado (opção 5):
```
    int main(){
        do{
            menu();
        } while (op != 5);
    
        return 0;
    }
```

#
#

### O que cada coisa faz?
1. `fptr` é uma variável do tipo `FILE`, que é usada para manipular arquivos em  C.
    - `FILE *`: é um tipo de dado em C que representa um arquivo;
    - `Fptr`: é o nome de variável que pode ser qualquer coisa, mas é mais comum usar fptr (que significa "file pointer").
    - `*`: indica que a variável é um ponteiro, ou seja, uma variável que contém um endereço de momória de outra variável
      
**Exemplos de uso:**
```
    FILE *fptr;  // Declaração de uma variável do tipo FILE *
    
    fptr = fopen("contatos.bin", "rb");  // Abre o arquivo "contatos.bin" para leitura binária
    
    fclose(fptr);  // Fecha o arquivo
```

2. `fopen` e `fclose`.
    - `fopen`: função usada para abrir um arquivo em C. ela tem que receber o nome do documento + o modo de abertura
          - `r` para ler
          - `w` para escrever
          - `a` para anexar
          - ...
    - `fclose`: função usada para fechar um arquivo que foi aberto anteriormente com o fopen.
      
**Exemplos de uso:**
```
    FILE *arquivo = fopen("dados.txt", "r");
```
```
    fclose(arquivo);
```

3. `fwrite` e `fread`.
    - `fwrite`: função usada para escrever dados em um arquivo binário. ela tem que receber um ponteiro para os dados serem escritos, o tamanho de cada elemento, o número  de elementos e um ponteiro para o arquivo
    - `fread`: função usada para ler dadis de um arquivo binário. ela tem que receber um ponteiro para armazenar os dados lidos, o tamanho de cada elemento a ser lido, o número de elementos e um ponteiro para o  arquivo
      
**Exemplos de uso:**
```
    fwrite(&contato, sizeof(Contato), 1, fptr);
```
```
    fread(&contato, sizeof(Contato), 1, fptr);
```

4. `sizeof`
    - `sizeof`: operador qye retorna o tamanho em bytes de um tipo de dados ou de uma variável. pode ser usado como tipo de dados primitivos, tipo: int, char, etc... ou com estruturas, tipo: Structs

**Exemplos de uso:**
```
    sizeof(int);     // Retorna o tamanho de um inteiro em bytes
    sizeof(Contato); // Retorna o tamanho da estrutura Contato em bytes
```

5. `remove` e `rename`.
    - `remove`: função usada para excluir um arquivo;
    - `rename`: função usada para renomear um arquivo.
      
**Exemplos de uso:**
```
    remove("arquivo.txt");
```
```
    rename("antigo.txt", "novo.txt");
```

6. `strcmp`
    - `strcmp`: função usada para comparar duas strings. Retorna um valor inteiro que indica se as strings são iguais (`0`), se a primeira é maior que a segunda (`> 0`), ou se a primeira é menor que a segunda (`< 0`)

**Exemplos de uso:**
```
    if (strcmp(contato.nome, n_pesq) == 0) {
        // As strings são iguais
    }
```
