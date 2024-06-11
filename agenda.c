#include <stdio.h>
#include <stdlib.h>

// prototipagem de funcs
int menu();
int add();
int consul();
int rm();

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
    int phone;              // troquei telefone por phone, só p encurtar
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
    // n sei como faço a consulta... vou pesqu um pouco
    // ideias?
}

// remover um contato existente
int rm(){
    
}

// func principal, raiz... onde vai ser tudo jogado, bjs
 int main(){
    int op;
    
    do {
        op = menu();
    } while (op !=4);

    return 0;
}
