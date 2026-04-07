# include <stdio.h>
# include <string.h>
# include <unistd.h>

# include "global_types.h"
# include "generate_data.h"
# include "add_book.h"
# include "refresh_append.h"
# include "get_indexes.h"
# include "linear_search.h"
# include "remove_book.h" 

# define DATA "books.txt" 
# define SIZE 300

int checkExists(){
    if (access(DATA, F_OK) == 0) {
        return 0;
    } else {
        printf("Criando arquivo\n");
        return 1;
    }
}

void menu(long greaterISBN, isbnIndex *isbn_array, TitleIndex *title_array, int n){
    int option;
    char prompt[50];
    int index;
    
    while(option != 4){
        printf("Bem vindo à Busca de Livros!\nSelecione uma operação:\n");
        printf("1- Inserir Livro\n2- Buscar Sequencial\n3- Buscar com Sentinela\n4- Remover Livro\n5- Sair\n");
        scanf("%d", &option);
        getchar();

        switch (option)
        {
        case 1:
            greaterISBN = refreshAppend(DATA);
            addBook(DATA, greaterISBN);
            break;
        case 2:
            printf("Digite o código do livro:\n");
            scanf("%15[^\n]%*c", prompt);

            printf("%d\n", buscaLinear(isbn_array, n, prompt));
            prompt[0] = '\0';
            
            break;
        case 3:
            printf("Digite o código do livro:\n");
            scanf("%15[^\n]%*c", prompt);

            index = buscaSentinela(isbn_array, n, prompt);
            printf("%d\n", index);
            // readByOffset(offset);

            prompt[0] = '\0';
            
            break;
        case 4:
            printf("Digite o código do livro:\n");
            scanf("%15[^\n]%*c", prompt);

            removeBook(DATA, isbn_array, n, prompt);
        case 5: 
            return;
        default:
            printf("Opção inválida! Selecione opção válida\n");
        }
    }

}

int main (){
    isbnIndex isbn_array[SIZE] = {0};
    AuthorIndex author_array[SIZE] = {0};
    TitleIndex title_array[SIZE] = {0};

    long greaterISBN;
    int count;

    int offset;

    if(checkExists() == 1){
        generateData();
    }

    count = getIndexes(DATA, isbn_array, author_array, title_array);

    imprimirTitleIndex(title_array, count);

    menu(greaterISBN, isbn_array, title_array, count);

    return 0;
    
}