# include <stdio.h>
# include <string.h>

# include "global_types.h"

int getIndexes(char *filename, isbnIndex *isbn_array, AuthorIndex *author_array, TitleIndex *title_array){
    FILE *f;
    f = fopen(filename, "r");

    int count = 0;

    char linha[300];
    char titulo[100], autor[100], isbn[15];

    int i = 0;

    while (fgets(linha, sizeof(linha), f)) {

        long pos = ftell(f);

        sscanf(linha, "%[^;];%[^;];%s",
               title_array[count].titulo, author_array[count].autor, isbn_array[count].isbn);
    
        isbn_array[count].offset = pos;
        author_array[count].offset = pos;
        title_array[count].offset = pos;

        count++;
    }

    fclose(f);

    return count;

}

void imprimirTitleIndex(TitleIndex indice[],
                        int total)
{
    for (int i = 0; i < total; i++) {

        printf("Indice %d:\n", i);
        printf("Titulo: %s\n", indice[i].titulo);
        printf("Offset: %ld\n", indice[i].offset);
        printf("\n");
    }
}