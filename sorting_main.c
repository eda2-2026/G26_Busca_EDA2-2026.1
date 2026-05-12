#include <stdio.h>

#include "sorting_algorithms.h"

static void printSortingMenu(void) {
    printf("\n=== Ordenacao de Livros por ISBN ===\n");
    printf("1 - Mostrar livros do arquivo\n");
    printf("2 - Demonstrar Bubble Sort\n");
    printf("3 - Demonstrar Selection Sort\n");
    printf("4 - Demonstrar Insertion Sort\n");
    printf("5 - Demonstrar Shell Sort\n");
    printf("6 - Demonstrar Quick Sort\n");
    printf("7 - Demonstrar Heap Sort\n");
    printf("8 - Demonstrar Merge Sort\n");
    printf("9 - Demonstrar Counting Sort\n");
    printf("10 - Demonstrar Radix Sort\n");
    printf("11 - Comparar todos os algoritmos\n");
    printf("12 - Sair\n");
    printf("Escolha: ");
}

static int runSingleSort(const SortEntry *entry, const Livro *base_books, int n) {
    Livro books[SORTING_MAX_BOOKS];
    clock_t start;
    clock_t elapsed;
    int success;

    copyBooks(books, base_books, n);

    printf("\nAntes da ordenacao (%s):\n", entry->name);
    printBooks(books, n);

    start = clock();
    success = entry->function(books, n);
    elapsed = clock() - start;

    if (!success) {
        printf("\n%s nao conseguiu ordenar este conjunto.\n", entry->name);
        return 0;
    }

    printf("\nDepois da ordenacao (%s):\n", entry->name);
    printBooks(books, n);

    printf("\nResumo:\n");
    printRunSummary(entry->name, elapsed, isSortedByIsbn(books, n));
    return 1;
}

static void compareAllSorts(const SortEntry *entries,
                            int total_entries,
                            const Livro *base_books,
                            int n) {
    Livro books[SORTING_MAX_BOOKS];

    printf("\nComparacao usando a mesma entrada embaralhada:\n");
    printf("%-15s | %-10s | %s\n", "Algoritmo", "Tempo", "Status");

    for (int i = 0; i < total_entries; i++) {
        clock_t start;
        clock_t elapsed;
        int success;

        copyBooks(books, base_books, n);

        start = clock();
        success = entries[i].function(books, n);
        elapsed = clock() - start;

        if (!success) {
            printf("%-15s | %8s | NAO EXECUTOU\n", entries[i].name, "-");
            continue;
        }

        printRunSummary(entries[i].name, elapsed, isSortedByIsbn(books, n));
    }
}

int main(void) {
    Livro books[SORTING_MAX_BOOKS];
    Livro shuffled_books[SORTING_MAX_BOOKS];
    int option = 0;
    int total_books;

    SortEntry entries[] = {
        {"Bubble Sort", bubbleSort},
        {"Selection Sort", selectionSort},
        {"Insertion Sort", insertionSort},
        {"Shell Sort", shellSort},
        {"Quick Sort", quickSortBooks},
        {"Heap Sort", heapSort},
        {"Merge Sort", mergeSortBooks},
        {"Counting Sort", countingSortBooks},
        {"Radix Sort", radixSortBooks}
    };
    int total_entries = (int) (sizeof(entries) / sizeof(entries[0]));

    if (!sortingDataExists(SORTING_DATA_FILE)) {
        generateData();
    }

    total_books = loadBooks(SORTING_DATA_FILE, books, SORTING_MAX_BOOKS);
    if (total_books <= 0) {
        printf("Nao foi possivel carregar %s.\n", SORTING_DATA_FILE);
        return 1;
    }

    copyBooks(shuffled_books, books, total_books);
    shuffleBooks(shuffled_books, total_books, 42U);

    while (option != 12) {
        printSortingMenu();
        if (scanf("%d", &option) != 1) {
            printf("Entrada invalida.\n");
            return 1;
        }

        switch (option) {
            case 1:
                printf("\nLivros no arquivo atual:\n");
                printBooks(books, total_books);
                break;
            case 2:
                runSingleSort(&entries[0], shuffled_books, total_books);
                break;
            case 3:
                runSingleSort(&entries[1], shuffled_books, total_books);
                break;
            case 4:
                runSingleSort(&entries[2], shuffled_books, total_books);
                break;
            case 5:
                runSingleSort(&entries[3], shuffled_books, total_books);
                break;
            case 6:
                runSingleSort(&entries[4], shuffled_books, total_books);
                break;
            case 7:
                runSingleSort(&entries[5], shuffled_books, total_books);
                break;
            case 8:
                runSingleSort(&entries[6], shuffled_books, total_books);
                break;
            case 9:
                runSingleSort(&entries[7], shuffled_books, total_books);
                break;
            case 10:
                runSingleSort(&entries[8], shuffled_books, total_books);
                break;
            case 11:
                compareAllSorts(entries, total_entries, shuffled_books, total_books);
                break;
            case 12:
                printf("Encerrando.\n");
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
    }

    return 0;
}
