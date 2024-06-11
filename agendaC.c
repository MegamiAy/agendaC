#include <stdio.h>
#include <stdlib.h>

// prototipagem de funcs aqui em cima


int main() {
    char nome[50];
    int telefone;
    FILE *fptr;
    fptr = fopen("contatos.txt", "w");
    if (fptr == NULL) {
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }

    printf("Nome do Contato: ");
    gets("%c", &nome[50]);
    printf("Telefone: ");
    fscanf("%i", telefone);
    fprintf(fptr, "%c %i", nome[50], telefone);
    fclose(fptr);
    return 0;
}

// Não sei se pode functions (se não puder a gente deleta tudo)
// acho que fica mais fácil se a gente fizer elas separadas e só juntas tudo no main

// int add(){
    
// }

// int consul(){
    
// }

// int rm(){
    
// }

// int menu(){
//  int op;
    
//  printf("Escolha qual vai ser sua acao nos contatos:\n 1. Adicionar\n 2. Pesquisar\n 3. Remover\n 4. Sair");
//  scanf("%i", &op);
    
//  switch(op){
//      case 1:
          // puxa a func de adição
//          break;
//      case 2:
          // puxa a func de consulta
//          break;
//      case 3:
          // puxa a func de remoção
//          break;
//      case 4:
          //encerra o programa
//      default:
//          printf("Esta opcao nao existe");
//          break;
//  }
    
// }

//Consultar um contato (listar/ler)

//Remover um contato

//Armazenar contatos (código binário)

//Menu (escolha: fazer, pesquisar, remover, sair)
}
