# include <stdio.h>

# define filename "books.txt"
# define greaterISBN 9780000000009

int main() {
    char titulo[50];
    char autor[50];

    printf("Digite o título:\n");
    scanf("%[^\n]", titulo);
    getchar();

    printf("\nDigite o autor:\n");
    scanf("%[^\n]", autor);
    getchar();

    FILE *f;

    f = fopen(filename, "a");
    fprintf(f, "%s;%s;%ld\n",
            titulo,
            autor,
            greaterISBN + 1);
    fclose(f);

    return 0;
}