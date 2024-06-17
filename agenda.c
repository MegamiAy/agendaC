// bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// tava lendo e é melhor dixar aq e cima
typedef struct{
    char nome[50];
    char fone[14];
} Contato;

// prototipagem de funções
int menu();
int add();
int consul();
int rm();
int load();

// variáveis globais

Contato contato;
int op;

// menu de ações
int menu(){
    printf("Escolha qual vai ser sua acao nos contatos:\n 1. Adicionar\n 2. Pesquisar\n 3. Remover\n 4. Bonus: Carregar todos\n 5. Sair\n ");
    scanf("%i", &op);
    switch(op){
        case 1:
            add();
            break;
        case 2:
            consul();
            break;
        case 3:
            rm();
            break;
        case 4:
            load();
            break;
        case 5:
            printf("Saindo do programa...");
            break;
        default:
            printf("Esta opcao nao existe");
            break;
    }
    return op;
} 

// incluir um novo contato
int add(){
    FILE *fptr;
    fptr = fopen("contatos.bin", "ab");
    if (fptr == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return 1;
    }

    printf("Nome do Contato: ");
    scanf("%s", contato.nome);
    fflush(stdin);

    printf("Telefone: ");
    scanf("%s", contato.fone);
    fflush(stdin);

    fwrite(&contato, sizeof(Contato), 1, fptr);
    fclose(fptr);
    
    return 0;
}

// listar/ler contatos existentes
int consul(){
    char n_pesq[50];
    int c_existe = 0;
    FILE *fptr;

    printf("Nome do contato para pesquisar: ");
    scanf("%s", n_pesq);

    if ((fptr = fopen("contatos.bin", "rb")) == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return 1;
    }
    while (fread(&contato, sizeof(Contato), 1, fptr)) {
        if (strcmp(contato.nome, n_pesq) == 0) {
            printf("Nome: %s\nTelefone: %s\n\n", contato.nome, contato.fone);
            c_existe = 1;
            break;
        }
    }
    if (c_existe == 0) {
        printf("Contato nao existe...\n");
    }

    fclose(fptr);
    return 0;
}
        
/*
size = 6;
numbers = [1, 2, 4, 87, 10]

numbers[3] = numbers[6-1]

size -- => size = 5

*/


// remover um contato existente - EM ANDAMENTO
int rm(){
    char n_pesq[50];
    int c_existe = 0;
    FILE *fptr, *temp;
    Contato temp_contato;
    /* Contato contatos[200]; */
    /* int index = 0; */

    printf("Nome do contato que deseja remover: ");
    scanf("%s", n_pesq);

    if ((fptr = fopen("contatos.bin", "rb")) == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return 1;
    }
    temp = fopen("temp.bin", "wb");
    if (temp == NULL) {
        printf("Erro ao criar arquivo temporário!\n");
        fclose(fptr);
        return 1;
    }

    while (fread(&contato, sizeof(Contato), 1, fptr)) {
        if (strcmp(contato.nome, n_pesq) == 0) {
            printf("Contato encontrado:\n");
            printf("Nome: %s\nTelefone: %s\n", contato.nome, contato.fone);
            c_existe = 1;
            int opR = 0;
            printf("Deseja realmente remover este contato?\n1. Sim\n2. Não\n");
            scanf("%i", &opR);
            switch (opR) {
                case 1:
                    // printf("Contato deletado");
                    break;
                case 2:
                    printf("\nAção cancelada.\n");
                    fwrite(&contato, sizeof(Contato), 1, temp);
                    break;
                default:
                    printf("\nOpção inválida.\n");
                    break;
            }
        } else {
            /* contatos[index++] = contato; */
            fwrite(&contato, sizeof(Contato), 1, temp);
        }
    }
    if (!c_existe) {
        printf("Contato não encontrado.\n");
    }

    fclose(fptr);
    fclose(temp);
    remove("contatos.bin");
    rename("temp.bin", "contatos.bin");

    /* for (int i = 0; i < index; i++) {
        fwrite(&contatos[i], sizeof(Contato), 1, fptr);
    }
        fwrite(contatos, sizeof(Contato), index; fptr);
    */

    return 0;
}

// carregar na tela os ctts existentes
int load(){
    FILE *fptr;
    fptr = fopen("contatos.bin", "rb");
    if (fptr == NULL) {
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }
    
    printf("\n=========\nContatos: \n\n");  
    while (fread(&contato, sizeof(Contato), 1, fptr)) {    
        printf("Nome: %s \nNumero: %s \n\n", contato.nome, contato.fone);
    }
    fclose(fptr);
    return 0;
}

// função principal, raiz
 int main(){
    do{
        menu();
    } while (op !=5);

    return 0;
}
