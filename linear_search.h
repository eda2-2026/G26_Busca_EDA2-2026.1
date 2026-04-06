#include <stdio.h>
#include <string.h>

# include "global_types.h"

void buscaLinear(char *filename, const char *tituloAlvo) {
    // for (int i = 0; i < n; i++) {
    //     if (strcmp(livros[i].titulo, tituloAlvo) == 0) {
    //         return i;
    //     }
    // }

    FILE *f;
    f = fopen(filename, "r");
    
    if(f == NULL){
        printf("Nada encontrado.\n");
        return;
    }

    char linha[300];
    char titulo[100], autor[100], isbn[15];

    while (fgets(linha, sizeof(linha), f)) {
        sscanf(linha, "%[^;];%[^;];%s",
               titulo, autor, isbn);
        if(strcmp(titulo, tituloAlvo) == 0){
            printf("Encontrado!\n%s\n%s\n%s\n", titulo, autor, isbn);
            fclose(f);
            return;
        }
    }

    fclose(f);

    printf("Nada encontrado.\n");
}

int buscaSentinelaOffset(isbnIndex *isbn_array, int n, const char *isbnAlvo) {
    strcpy(isbn_array[n].isbn, isbnAlvo); 
    int i = 0;
    while (strcmp(isbn_array[i].isbn, isbnAlvo) != 0) {
        i++;
    }
    if (i < n) {
        return isbn_array[i].offset; 
    }
    return -1; 
}