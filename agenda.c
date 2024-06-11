// bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// prototipagem de funções
int menu();
int add();
int consul();
int rm();
int load();

// variáveis globais
typedef struct{
    char nome[50];
    char fone[14];
} Contato;
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

    // usuário insere os dados
    printf("Nome do Contato: ");
    scanf("%s", contato.nome);
    fflush(stdin);

    printf("Telefone: ");
    scanf("%s", contato.fone);
    fflush(stdin);

    // salva no arquivo
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

    if ((fptr = fopen("contatos.bin","rb")) == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return 1;
    }
    while(fread(&contato, sizeof(Contato), 1, fptr)){
        if(strcmp(contato.nome, n_pesq) == 0){
            printf("Nome: %s\nTelefone: %s\n\n", contato.nome, contato.fone);
            c_existe = 1;
            break;
        }
    }
    if(c_existe == 0){
        printf("Contato nao existe...\n");
        return 1;
    }

    fclose(fptr);
    return 0;
}
        

// remover um contato existente
int rm(){
    
}

// carregar na tela os ctts existentes
int load(){
    FILE *fptr;
    fptr = fopen("contatos.bin", "rb");
    if(fptr == NULL){
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }
    
    printf("Contatos: \n");
    while(fscanf(fptr, "%s %s", contato.nome, contato.fone) != EOF){      
        printf("Nome: %s \nNumero: %s \n\n", contato.nome, contato.fone);
    }
}

// função principal, raiz
 int main(){
    do{
        int op;
        menu();
    } while (op !=5);

    return 0;
}
