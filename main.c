# include <stdio.h>
# include <unistd.h>

# define DATA "books.txt" 

typedef struct
{
    int idLivro;
    char titulo[50];
    char autor[50];
    // int idCategoria;
    char isbn[14];
} Livro;

typedef struct
{
    char nomeAutor[50];
    int posicoes[50];
    int ocorrencias;
} AutorIndice;

// typedef struct 
// {
//     Livro dados;
//     NodeLivro *next;
// } NodeLivro;

// typedef struct
// {
//     NodeLivro *inicio;
// } Lista;

int checkExists(){
    if (access(DATA, F_OK) == 0) {
        return 1;
    } else {
        printf("Criando arquivo\n");
        return 0;
    }
}

void inserirLivro(){
    FILE *fptr;

    fptr = fopen('books.txt', 'w');
}

int main (){
    Livro livros[300] = {0};
}