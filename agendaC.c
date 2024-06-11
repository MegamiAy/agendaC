//Adicionar um contato
#include <stdio.h>
#include <stdlib.h>

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

//Consultar um contato (listar/ler)

//Remover um contato

//Armazenar contatos (código binário)

//Menu (escolha: fazer, pesquisar, remover, sair)