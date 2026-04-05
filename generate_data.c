#include <stdio.h>

int main() {

    FILE *f;

    f = fopen("books.txt", "w");

    for(int i = 1; i <= 300; i++) {

        fprintf(f,
            "%d;Livro %d;Autor %d;%ld\n",
            i,
            i,
            i % 20,
            9780000000000 + i
        );
    }

    fclose(f);

    return 0;
}