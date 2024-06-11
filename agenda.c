// bibliotecas
#include <stdio.h>
#include <stdlib.h>

// prototipagem de funcs
int menu();
int add();
int consul();
int rm();
int load();

// declarando as variáveis
char nome[50];
int phone, op;

// menu de ações
int menu(){
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
    scanf("%d", &phone);
    fflush(stdin);
    fprintf(fptr, "Nome: %s \t Numero: %d \n\n", nome, phone);
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
    fscanf(fptr, "%i", &phone);
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
    FILE *fptr;
    fptr = fopen("contatos.txt", "r");
    if(fptr == NULL){
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }
     
    printf("Contatos: \n");
    while(fscanf(fptr, "%s %d", nome, &phone) != EOF){      // enquanto os registros não estiverem no fim do arquivo, n for o último, ele continua dando printf no ctt
        printf("Nome: %s \n Numero: %d \n\n", nome, phone);
    }
    
    fclose(fptr);
}

// func principal, raiz... onde vai ser tudo jogado, bjs
 int main(){
    load();
     
    do {
        op = menu();
    } while (op !=4);

    return 0;
}
