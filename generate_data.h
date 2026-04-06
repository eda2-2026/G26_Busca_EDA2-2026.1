#include <stdio.h>

void generateData() {

    FILE *f;

    f = fopen("books.txt", "w");

    for(int i = 1; i <= 10; i++) {

        fprintf(f,
            "Livro %d;Autor %d;%ld\n",
            i,
            i % 20,
            9780000000000 + i
        );
    }

    fclose(f);
}

