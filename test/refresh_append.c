# include <stdio.h>
# include <stdlib.h>

# define filename "books.txt"

// O(n);

int main(){
    FILE *f;
    f = fopen(filename, "r");
    
    if(f == NULL){
        printf("Is NULL");
        return 0;
    }

    char linha[300];
    char titulo[100], autor[100], isbn[15];

    long long isbnToCompare = 0;

    while (fgets(linha, sizeof(linha), f)) {

        sscanf(linha, "%[^;];%[^;];%s",
               titulo, autor, isbn);

        

        if (isbnToCompare > strtoll(isbn, NULL, 10)) {
            continue;
        }else{
            isbnToCompare = strtoll(isbn, NULL, 10);
        }
    }

    char buffer[21];

    snprintf(buffer, sizeof(buffer), "%lld", isbnToCompare);

    printf("String value: %s\n", buffer);

    return 0;

}