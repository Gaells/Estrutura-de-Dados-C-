#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Método Bubble Sort (ordem crescente)
void BubbleSort(char A[], int n) {
    int i, j, troca;
    for (i = n - 1; i >= 1; i--) {
        for (j = 0; j < i; j++) {
            if (A[j] > A[j + 1]) {
                troca = A[j];
                A[j] = A[j + 1];
                A[j + 1] = troca;
            }
        }
    }
}

// Método Selection Sort (ordem decrescente)
void SelectionSort(char A[], int n) {
    int i, j, aux, maior;
    for (i = 0; i < n - 1; i++) {
        maior = i;
        for (j = i + 1; j < n; j++) {
            if (A[j] > A[maior])
                maior = j;
        }
        aux = A[i];
        A[i] = A[maior];
        A[maior] = aux;
    }
}

int main() {
    char vetNome[24] = {'G', 'A', 'B', 'R', 'I', 'E', 'L', 'C', 'H', 'I', 'O', 'Q', 'U', 'E', 'T', 'T', 'A', 'O', 'B', 'L', 'A', 'D', 'E', 'N'};
    char vetNomeDupli[24];

    // Copiar o conteúdo do vetor vetNome para vetNomeDupli
    for (int i = 0; i < 24; i++) {
        vetNomeDupli[i] = vetNome[i];
    }

    // Bubble Sort
    printf("Valores do vetor antes de ordenar por Bubble Sort:\n");
    for (int x = 0; x < 24; x++)
        printf("%c ", vetNome[x]);

    BubbleSort(vetNome, 24);

    printf("\nValores do vetor depois de ordenar por Bubble Sort:\n");
    for (int x = 0; x < 24; x++)
        printf("%c ", vetNome[x]);

    // Selection Sort
    printf("\nValores do vetor antes de ordenar por Selection Sort:\n");
    for (int x = 0; x < 24; x++)
        printf("%c ", vetNomeDupli[x]);

    SelectionSort(vetNomeDupli, 24);

    printf("\nValores do vetor depois de ordenar por Selection Sort:\n");
    for (int x = 0; x < 24; x++)
        printf("%c ", vetNomeDupli[x]);

    // Medição do tempo de execução
    clock_t inicio, fim;
    double tempoBubbleSort, tempoSelectionSort;
    int iteracoes = 100000;

    // Bubble Sort
    inicio = clock();
    for (int i = 0; i < iteracoes; i++) {
        BubbleSort(vetNome, 24);
    }
    fim = clock();
    tempoBubbleSort = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    // Selection Sort
    inicio = clock();
    for (int i = 0; i < iteracoes; i++) {
        SelectionSort(vetNomeDupli, 24);
    }
    fim = clock();
    tempoSelectionSort = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("\n\nTempo de execucao (Bubble Sort): %.6f segundos\n", tempoBubbleSort);
    printf("Tempo de execucao (Selection Sort): %.6f segundos\n", tempoSelectionSort);

    return 0;
}

