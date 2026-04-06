#include <stdio.h>
#include <string.h>

# include "global_types.h"

int buscaLinear(TitleIndex *title_array, int n, const char *tituloAlvo) {
    for (int i = 0; i < n; i++) {

        if (strcmp(title_array[i].titulo, tituloAlvo) == 0) {
            return i;
        }
    }
    return -1;
}

int buscaSentinelaOffset(TitleIndex *title_array, int n, const char *tituloAlvo) {
    strcpy(title_array[n].titulo, tituloAlvo); 
    int i = 0;
    while (strcmp(title_array[i].titulo, tituloAlvo) != 0) {
        i++;
    }
    if (i < n) {
        return title_array[i].offset; 
    }
    return -1; 
}