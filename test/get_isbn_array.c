# include <stdio.h>
# include <string.h>

# define filename "books.txt"

char isbn_array[300][15] = {0};

typedef struct {
    char isbn[15];
    long offset;
} isbnIndex;

int main(){
    FILE *f;
    f = fopen(filename, "r");

    int count = 0;
    isbnIndex indices[300];

    char linha[300];
    char titulo[100], autor[100], isbn[15];

    int i = 0;

    while (fgets(linha, sizeof(linha), f)) {

        long pos = ftell(f);

        sscanf(linha, "%[^;];%[^;];%s",
               titulo, autor, indices[count].isbn);
    
        indices[count].offset = pos;

        printf("%s\n%ld\n", indices[count].isbn, indices[count].offset);

        count++;
    }

    printf("%d", count);

    return 0;

}