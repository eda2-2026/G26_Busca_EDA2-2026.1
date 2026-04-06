# include <stdio.h>
# include <string.h>

# include "global_types.h"

int getISBNs(char *filename, isbnIndex *isbn_array){
    FILE *f;
    f = fopen(filename, "r");

    int count = 0;

    char linha[300];
    char titulo[100], autor[100], isbn[15];

    int i = 0;

    while (fgets(linha, sizeof(linha), f)) {

        long pos = ftell(f);

        sscanf(linha, "%[^;];%[^;];%s",
               titulo, autor, isbn_array[count].isbn);
    
        isbn_array[count].offset = pos;

        count++;
    }

    fclose(f);

    return count;

}