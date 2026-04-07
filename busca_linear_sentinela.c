#include <stdio.h>
#include <string.h>

typedef struct {
    int idLivro;
    char titulo[50];
    char autor[50];
    char isbn[14];
} Livro;

int buscaLinear(Livro livros[], int n, const char *tituloAlvo) {
    for (int i = 0; i < n; i++) {
        if (strcmp(livros[i].titulo, tituloAlvo) == 0) {
            return i;
        }
    }
    return -1;
}

int buscaSentinela(Livro livros[], int n, const char *isbnAlvo) {
    strcpy(livros[n].isbn, isbnAlvo);
    int i = 0;
    while (strcmp(livros[i].isbn, isbnAlvo) != 0) {
        i++;
    }
    if (i < n) {
        return i;
    }
    return -1;
}

int buscaLinearMoverParaFrente(Livro livros[], int n, const char *tituloAlvo) {
    int i = 0;
    while (i < n && strcmp(livros[i].titulo, tituloAlvo) != 0) {
        i++;
    }
    if (i >= n) {
        return -1;
    }
    if (i == 0) {
        return 0;
    }
    Livro encontrado = livros[i];
    for (int j = i; j > 0; j--) {
        livros[j] = livros[j - 1];
    }
    livros[0] = encontrado;
    return 0;
}

int buscaLinearTransposicao(Livro livros[], int n, const char *tituloAlvo) {
    int i = 0;
    while (i < n && strcmp(livros[i].titulo, tituloAlvo) != 0) {
        i++;
    }
    if (i >= n) {
        return -1;
    }
    if (i == 0) {
        return 0;
    }
    Livro tmp = livros[i];
    livros[i] = livros[i - 1];
    livros[i - 1] = tmp;
    return i - 1;
}

int main() {
    printf("Sistema de Busca de Livros\n");

    Livro mocks[6] = {
        {1, "Dom Casmurro", "Machado de Assis", "9781234567890"},
        {2, "Memórias Póstumas", "Machado de Assis", "9781234567891"},
        {3, "A Hora da Estrela", "Clarice Lispector", "9781234567892"},
        {4, "O Alquimista", "Paulo Coelho", "9781234567893"},
        {5, "Saramago", "José Saramago", "9781234567894"}
    };

    int idx = buscaLinear(mocks, 5, "A Hora da Estrela");
    if (idx != -1) {
        printf("Busca Linear: Encontrado '%s' no índice %d\n", mocks[idx].titulo, idx);
    } else {
        printf("Busca Linear: Não encontrado\n");
    }

    idx = buscaSentinela(mocks, 5, "9781234567891");
    if (idx != -1) {
        printf("Busca Sentinela: Encontrado ISBN '%s' no índice %d\n", mocks[idx].isbn, idx);
    } else {
        printf("Busca Sentinela: Não encontrado\n");
    }

    idx = buscaLinear(mocks, 5, "Harry Potter");
    printf("Linear inexistente: %d\n", idx);

    idx = buscaSentinela(mocks, 5, "0000000000000");
    printf("Sentinela inexistente: %d\n", idx);

    Livro mtf[6] = {
        {1, "Dom Casmurro", "Machado de Assis", "9781234567890"},
        {2, "Memórias Póstumas", "Machado de Assis", "9781234567891"},
        {3, "A Hora da Estrela", "Clarice Lispector", "9781234567892"},
        {4, "O Alquimista", "Paulo Coelho", "9781234567893"},
        {5, "Saramago", "José Saramago", "9781234567894"}
    };
    idx = buscaLinearMoverParaFrente(mtf, 5, "O Alquimista");
    if (idx != -1) {
        printf("MTF: %s [%d]\n", mtf[0].titulo, idx);
    }

    Livro tp[6] = {
        {1, "Dom Casmurro", "Machado de Assis", "9781234567890"},
        {2, "Memórias Póstumas", "Machado de Assis", "9781234567891"},
        {3, "A Hora da Estrela", "Clarice Lispector", "9781234567892"},
        {4, "O Alquimista", "Paulo Coelho", "9781234567893"},
        {5, "Saramago", "José Saramago", "9781234567894"}
    };
    idx = buscaLinearTransposicao(tp, 5, "A Hora da Estrela");
    if (idx != -1) {
        printf("Transposição: %s [%d]\n", tp[idx].titulo, idx);
    }
    idx = buscaLinearTransposicao(tp, 5, "Livro Inexistente");
    printf("Transposição inexistente: %d\n", idx);

    return 0;
}
