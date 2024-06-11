// bibliotecas
#include <stdio.h>
#include <stdlib.h>

// prototipagem de funcs
int menu();
int add();
int consul();
int rm();
int load();

// menu de ações
int menu(){
    int op;
    
    printf("Escolha qual vai ser sua acao nos contatos:\n 1. Adicionar\n 2. Pesquisar\n 3. Remover\n 4. Sair\n");
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
    char nome[50];
    int phone[11];              // troquei telefone por phone, só p encurtar
    FILE *fptr;
    fptr = fopen("contatos.txt", "a");
    if (fptr == NULL) {
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }

    printf("Nome do Contato: ");
    gets("%s", &nome);              // só troquei de ("%c", &nome[50]) para ("%s", &nome) pq tá lendo uma string, bele?
    printf("Telefone: ");
    fscanf("%d", phone);            
    fprintf(fptr, "%s %d", nome, phone);
    fclose(fptr);
    
    return 0;
}

// listar/ler contatos existentes
int consul(){
    int phone[11];
    char nome[50];
    FILE *fptr;
    if ((fptr = fopen("contatos.txt","r")) == NULL) {
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }
    fscanf(fptr, "%c", &nome[50]);
    fscanf(fptr, "%i", &phone[11]);
    printf("Nome: %s\n", nome);
    printf("Telefone: %i\n\n", phone);
    fclose(fptr);
    return 0;
}
        

// remover um contato existente
int rm(){
    
}

// carregar na tela os ctts existentes
int load(){
    
}

// func principal, raiz... onde vai ser tudo jogado, bjs
 int main(){
    int op;
    
    do {
        op = menu();
    } while (op !=4);

    return 0;
}
