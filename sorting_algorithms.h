#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <limits.h>
#include <stdlib.h>

#include "sorting_support.h"

typedef int (*SortFunction)(Livro *books, int n);

static int bubbleSort(Livro *books, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (isbnToNumber(books[j].isbn) > isbnToNumber(books[j + 1].isbn)) {
                swapBook(&books[j], &books[j + 1]);
            }
        }
    }
    return 1;
}

static int selectionSort(Livro *books, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (isbnToNumber(books[j].isbn) < isbnToNumber(books[min_index].isbn)) {
                min_index = j;
            }
        }
        if (min_index != i) {
            swapBook(&books[i], &books[min_index]);
        }
    }
    return 1;
}

static int insertionSort(Livro *books, int n) {
    for (int i = 1; i < n; i++) {
        Livro current = books[i];
        long long key = isbnToNumber(current.isbn);
        int j = i - 1;

        while (j >= 0 && isbnToNumber(books[j].isbn) > key) {
            books[j + 1] = books[j];
            j--;
        }
        books[j + 1] = current;
    }
    return 1;
}

static int shellSort(Livro *books, int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            Livro current = books[i];
            long long key = isbnToNumber(current.isbn);
            int j = i;

            while (j >= gap && isbnToNumber(books[j - gap].isbn) > key) {
                books[j] = books[j - gap];
                j -= gap;
            }
            books[j] = current;
        }
    }
    return 1;
}

static int partitionBooks(Livro *books, int low, int high) {
    long long pivot = isbnToNumber(books[high].isbn);
    int smaller = low - 1;

    for (int j = low; j < high; j++) {
        if (isbnToNumber(books[j].isbn) <= pivot) {
            smaller++;
            swapBook(&books[smaller], &books[j]);
        }
    }

    swapBook(&books[smaller + 1], &books[high]);
    return smaller + 1;
}

static void quickSortRecursive(Livro *books, int low, int high) {
    if (low < high) {
        int pivot = partitionBooks(books, low, high);
        quickSortRecursive(books, low, pivot - 1);
        quickSortRecursive(books, pivot + 1, high);
    }
}

static int quickSortBooks(Livro *books, int n) {
    if (n > 1) {
        quickSortRecursive(books, 0, n - 1);
    }
    return 1;
}

static void heapify(Livro *books, int n, int root) {
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < n && isbnToNumber(books[left].isbn) > isbnToNumber(books[largest].isbn)) {
        largest = left;
    }
    if (right < n && isbnToNumber(books[right].isbn) > isbnToNumber(books[largest].isbn)) {
        largest = right;
    }

    if (largest != root) {
        swapBook(&books[root], &books[largest]);
        heapify(books, n, largest);
    }
}

static int heapSort(Livro *books, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(books, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swapBook(&books[0], &books[i]);
        heapify(books, i, 0);
    }
    return 1;
}

static void merge(Livro *books, int left, int middle, int right, Livro *temp) {
    int i = left;
    int j = middle + 1;
    int k = left;

    while (i <= middle && j <= right) {
        if (isbnToNumber(books[i].isbn) <= isbnToNumber(books[j].isbn)) {
            temp[k++] = books[i++];
        } else {
            temp[k++] = books[j++];
        }
    }

    while (i <= middle) {
        temp[k++] = books[i++];
    }
    while (j <= right) {
        temp[k++] = books[j++];
    }

    for (i = left; i <= right; i++) {
        books[i] = temp[i];
    }
}

static void mergeSortRecursive(Livro *books, int left, int right, Livro *temp) {
    if (left >= right) {
        return;
    }

    int middle = left + (right - left) / 2;
    mergeSortRecursive(books, left, middle, temp);
    mergeSortRecursive(books, middle + 1, right, temp);
    merge(books, left, middle, right, temp);
}

static int mergeSortBooks(Livro *books, int n) {
    Livro *temp = (Livro *) malloc((size_t) n * sizeof(Livro));

    if (temp == NULL) {
        return 0;
    }

    mergeSortRecursive(books, 0, n - 1, temp);
    free(temp);
    return 1;
}

static int countingSortBooks(Livro *books, int n) {
    long long min = isbnToNumber(books[0].isbn);
    long long max = min;

    for (int i = 1; i < n; i++) {
        long long value = isbnToNumber(books[i].isbn);
        if (value < min) {
            min = value;
        }
        if (value > max) {
            max = value;
        }
    }

    if (max < min) {
        return 0;
    }

    long long range = max - min + 1;
    if (range <= 0 || range > 1000000) {
        return 0;
    }

    int *count = (int *) calloc((size_t) range, sizeof(int));
    Livro *output = (Livro *) malloc((size_t) n * sizeof(Livro));

    if (count == NULL || output == NULL) {
        free(count);
        free(output);
        return 0;
    }

    for (int i = 0; i < n; i++) {
        count[isbnToNumber(books[i].isbn) - min]++;
    }

    for (long long i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        long long key = isbnToNumber(books[i].isbn) - min;
        output[count[key] - 1] = books[i];
        count[key]--;
    }

    for (int i = 0; i < n; i++) {
        books[i] = output[i];
    }

    free(count);
    free(output);
    return 1;
}

static void countingPassByDigit(Livro *books, int n, long long exponent, long long min) {
    Livro *output = (Livro *) malloc((size_t) n * sizeof(Livro));
    int count[10] = {0};

    if (output == NULL) {
        return;
    }

    for (int i = 0; i < n; i++) {
        long long normalized = isbnToNumber(books[i].isbn) - min;
        int digit = (int) ((normalized / exponent) % 10);
        count[digit]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        long long normalized = isbnToNumber(books[i].isbn) - min;
        int digit = (int) ((normalized / exponent) % 10);
        output[count[digit] - 1] = books[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++) {
        books[i] = output[i];
    }

    free(output);
}

static int radixSortBooks(Livro *books, int n) {
    long long min = isbnToNumber(books[0].isbn);
    long long max = min;

    for (int i = 1; i < n; i++) {
        long long value = isbnToNumber(books[i].isbn);
        if (value < min) {
            min = value;
        }
        if (value > max) {
            max = value;
        }
    }

    long long normalized_max = max - min;
    for (long long exponent = 1; normalized_max / exponent > 0; exponent *= 10) {
        countingPassByDigit(books, n, exponent, min);
    }

    return 1;
}

typedef struct {
    const char *name;
    SortFunction function;
} SortEntry;

#endif
