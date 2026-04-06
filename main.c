# include <stdio.h>
# include <string.h>
# include <unistd.h>

# include "generate_data.h"
# include "add_book.h"
# include "refresh_append.h"

# define DATA "books.txt" 
# define SIZE 300

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
        return 0;
    } else {
        printf("Criando arquivo\n");
        return 1;
    }
}


int main (){
    Livro livros[SIZE] = {0};

    int book_stored = 0;
    long greaterISBN;

    int option;

    if(checkExists() == 1){
        generateData();
    }

    while(option != 3){
        printf("Bem vindo à Busca de Livros!\nSelecione uma operação:\n");
        printf("1- Inserir Livro\n2- Buscar Livro\n3- Sair\n");
        scanf("%d", &option);
        getchar();

        greaterISBN = refreshAppend(DATA);

        switch (option)
        {
        case 1:
            addBook(DATA, greaterISBN);
            break;
        case 2:
            break;
        case 3:
            return 0;
            break;
        default:
            printf("Opção inválida! Selecione opção válida\n");
        }
    }

    return 0;
    
}