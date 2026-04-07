# include <stdio.h>
# include "global_types.h"
# include "linear_search.h"

void removeBook(char *filename, isbnIndex *isbn_array, int n, char *isbnAlvo){
    int toBeRemoved = buscaSentinela(isbn_array, n, isbnAlvo);
    if (toBeRemoved < 0) {
        return;
    }

    FILE *f1, *f2;
    f1 = fopen("swap.txt", "w");
    f2 = fopen(filename, "r");

    char linha[300];

    while (fgets(linha, sizeof(linha), f2)){
        if(toBeRemoved == 0){
            toBeRemoved--;
            continue;
        }else if(toBeRemoved >= 0){
            toBeRemoved--;
        }
        fprintf(f1, "%s", linha);
    }

    fclose(f1);
    fclose(f2);

    remove("books.txt");
    rename("swap.txt", "books.txt");
}