#include <stdio.h>

void addBook(char *filename, long greaterISBN) {
    char titulo[50];
    char autor[50];

    printf("Digite o título:\n");
    scanf("%[^\n]", titulo);
    getchar();

    printf("\nDigite o autor:\n");
    scanf("%[^\n]", autor);
    getchar();

    FILE *f;

    f = fopen(filename, "a");
    fprintf(f, "%s;%s;%ld\n",
            titulo,
            autor,
            greaterISBN + 1);
    fclose(f);

}