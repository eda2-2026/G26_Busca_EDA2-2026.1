#ifndef SORTING_SUPPORT_H
#define SORTING_SUPPORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "global_types.h"
#include "generate_data.h"

#define SORTING_DATA_FILE "books.txt"
#define SORTING_MAX_BOOKS 300

static long long isbnToNumber(const char *isbn) {
    return strtoll(isbn, NULL, 10);
}

static int sortingDataExists(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return 0;
    }
    fclose(file);
    return 1;
}

static int loadBooks(const char *filename, Livro *books, int max_books) {
    FILE *file = fopen(filename, "r");
    char line[256];
    int count = 0;

    if (file == NULL) {
        return 0;
    }

    while (count < max_books && fgets(line, sizeof(line), file) != NULL) {
        if (sscanf(line, "%49[^;];%49[^;];%13s",
                   books[count].titulo,
                   books[count].autor,
                   books[count].isbn) == 3) {
            books[count].idLivro = count + 1;
            count++;
        }
    }

    fclose(file);
    return count;
}

static void copyBooks(Livro *dest, const Livro *src, int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

static void printBooks(const Livro *books, int n) {
    for (int i = 0; i < n; i++) {
        printf("%2d. %-12s | %-10s | %s\n",
               i + 1,
               books[i].titulo,
               books[i].autor,
               books[i].isbn);
    }
}

static void swapBook(Livro *left, Livro *right) {
    Livro temp = *left;
    *left = *right;
    *right = temp;
}

static void shuffleBooks(Livro *books, int n, unsigned int seed) {
    srand(seed);
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swapBook(&books[i], &books[j]);
    }
}

static int isSortedByIsbn(const Livro *books, int n) {
    for (int i = 1; i < n; i++) {
        if (isbnToNumber(books[i - 1].isbn) > isbnToNumber(books[i].isbn)) {
            return 0;
        }
    }
    return 1;
}

static void printRunSummary(const char *name, clock_t elapsed, int sorted) {
    double ms = (double) elapsed * 1000.0 / CLOCKS_PER_SEC;
    printf("%-15s | %8.3f ms | %s\n",
           name,
           ms,
           sorted ? "OK" : "FALHOU");
}

#endif
