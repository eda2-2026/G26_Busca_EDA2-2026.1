# include <stdio.h>
# include <string.h>
# include <unistd.h>

# include "global_types.h"
# include "generate_data.h"
# include "add_book.h"
# include "refresh_append.h"
# include "get_isbn_array.h"
# include "linear_search.h"

# define DATA "books.txt" 
# define SIZE 300

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

void readByOffset(int offset){
    FILE *f = fopen(DATA, "r");

    if (f == NULL)
        return;

    char linha[300];
    char titulo[50];
    char autor[50];
    char isbn[15];

    fseek(f, offset, SEEK_SET);

    fgets(linha, sizeof(linha), f);
    sscanf(linha, "%[^;];%[^;];%s",
               titulo, autor, isbn);

    fclose(f);

    printf("Encontrado!\n%s\n%s\n%s\n", titulo, autor, isbn);
}


int main (){
    isbnIndex isbn_array[SIZE] = {0};
    long greaterISBN;
    int count;

    int option;
    char prompt[50];

    int offset;

    if(checkExists() == 1){
        generateData();
    }

    count = getISBNs(DATA, isbn_array);

    while(option != 4){
        printf("Bem vindo à Busca de Livros!\nSelecione uma operação:\n");
        printf("1- Inserir Livro\n2- Buscar por Título\n3- Buscar por Código\n4- Sair\n");
        scanf("%d", &option);
        getchar();

        switch (option)
        {
        case 1:
            greaterISBN = refreshAppend(DATA);
            addBook(DATA, greaterISBN);
            break;
        case 2:
            printf("Digite o título do livro:\n");
            scanf("%49[^\n]%*c", prompt);

            buscaLinear(DATA, prompt);
            prompt[0] = '\0';
            
            break;
        case 3:
            printf("Digite o código do livro:\n");
            scanf("%15[^\n]%*c", prompt);

            offset = buscaSentinelaOffset(isbn_array, count, prompt);

            readByOffset(offset);

            prompt[0] = '\0';
            
            break;
        case 4: 
            return 0;
        default:
            printf("Opção inválida! Selecione opção válida\n");
        }
    }

    return 0;
    
}