//C ANSI


//ESCREVER EM ARQUIVO C
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num;
    FILE *fptr;
    fptr = fopen("programa.txt", "w");
    if (fptr == NULL) {
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }

    printf("Entre um número: ");
    scanf("%d", &num);
    fprintf(fptr, "%d", num);
    fclose(fptr);
    return 0;
}


//LER ARQUIVO C
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num;
    FILE *fptr;
    fptr = fopen("programa.txt", "r");
    if (fptr == NULL) {
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }

    fscanf(fptr, "%d", &num);
    printf("Valor do número: %d\n", num);
    fclose(fptr);
    return 0;
}


//ESCREVER EM ARQUIVO BINÁRIO
#include <stdio.h>
#include <stdlib.h>
struct threeNum { int n1, n2, n3; };

int main() {
    struct threeNum num;
    FILE *fptr;
    fptr = fopen("program.bin", "wb");
    if (fptr == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    for (int n = 1; n < 5; n++) {
        num.n1 = n;
        num.n2 = 4 * n;
        num.n3 = 4 * n + 1;
        fwrite(&num, sizeof(struct threeNum), 1, fptr);
    }
    fclose(fptr);

    return 0;
}


//LER ARQUIVO BINÁRIO
#include <stdio.h>
#include <stdlib.h>
struct threeNum { int n1, n2, n3; };

int main() {
    struct threeNum num;
    FILE *fptr;
    fptr = fopen("program.bin", "rb");
    if (fptr == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    for (int n = 1; n < 5; n++) {
        fread(&num, sizeof(struct threeNum), 1, fptr);
        printf("n1: %d\tn2: %d\tn3: %d\n", num.n1, num.n2, num.n3);
    }
    fclose(fptr);

    return 0;
}