#ifndef LINEAR_SEARCH_H
#define LINEAR_SEARCH_H

#include <stdio.h>
#include <string.h>

# include "global_types.h"

int buscaLinear(isbnIndex *isbn_array, int n, const char *isbnAlvo) {
    for (int i = 0; i < n; i++) {

        if (strcmp(isbn_array[i].isbn, isbnAlvo) == 0) {
            return i;
        }
    }
    return -1;
}

int buscaSentinela(isbnIndex *isbn_array, int n, const char *isbnAlvo) {
    strcpy(isbn_array[n].isbn, isbnAlvo); 
    int i = 0;
    while (strcmp(isbn_array[i].isbn, isbnAlvo) != 0) {
        i++;
    }
    if (i < n) {
        return i;
    }
    return -1; 
}

#endif