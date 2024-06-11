// bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// prototipagem de funcs
int menu();
int add();
int consul();
int rm();
int load();

// declarando as variáveis
char nome[50], phone[14];
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
    fptr = fopen("contatos.txt", "a");
    if (fptr == NULL) {
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }

    printf("Nome do Contato: ");
    scanf("%s", nome);
    fflush(stdin);
    printf("Telefone: ");
    scanf("%s", phone);
    fflush(stdin);
    fprintf(fptr, "Nome: %s \t Numero: %s \n\n", nome, phone);
    fclose(fptr);
    
    return 0;
}

// listar/ler contatos existentes
int consul(){
    FILE *fptr;
    if ((fptr = fopen("contatos.txt","r")) == NULL) {
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }
    fscanf(fptr, "%s", nome);
    fscanf(fptr, "%s", phone);
    printf("Nome: %s\n", nome);
    printf("Telefone: %s\n\n", phone);
    fclose(fptr);
    return 0;
}
        

// remover um contato existente
int rm(){
    
}

// carregar na tela os ctts existentes
int load(){
    FILE *fptr;
    fptr = fopen("contatos.txt", "r");
    if(fptr == NULL){
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }
    
    printf("Contatos: \n");
    while(fscanf(fptr, "%s %s", nome, phone) != EOF){      
        printf("Nome: %s \n Numero: %s \n\n", nome, phone);
    }
}

// func principal, raiz... onde vai ser tudo jogado, bjs
 int main(){
    do {
        op = menu();
    } while (op !=5);

    return 0;
}