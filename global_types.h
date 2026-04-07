#ifndef MY_TYPES_H
#define MY_TYPES_H

typedef struct
{
    char autor[50];
    long offset;
} AuthorIndex;

typedef struct
{
    char titulo[50];
    long offset;
} TitleIndex;


typedef struct {
    char isbn[15];
    long offset;
} isbnIndex;

typedef struct
{
    int idLivro;
    char titulo[50];
    char autor[50];
    // int idCategoria;
    char isbn[14];
} Livro;

#endif