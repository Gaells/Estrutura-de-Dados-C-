#include <stdio.h>

#define TAMANHO_ARRAY 5

int main() {
    int array[TAMANHO_ARRAY];
    int *ponteiro_array = array; // ponteiro para o início do array
    int segundo_array[TAMANHO_ARRAY];

    // leitura dos valores do array via teclado
    for (int i = 0; i < TAMANHO_ARRAY; i++) {
        printf("Digite o valor para o elemento %d: ", i);
        scanf("%d", ponteiro_array+i); // leitura via ponteiro
    }

    // cópia dos valores do primeiro array para o segundo array
    for (int i = 0; i < TAMANHO_ARRAY; i++) {
        *(segundo_array+i) = *(ponteiro_array+i); // acesso aos elementos via ponteiro
    }

    // impressão dos valores do segundo array
    printf("Segundo array:\n");
    for (int i = 0; i < TAMANHO_ARRAY; i++) {
        printf("%d ", *(segundo_array+i)); // acesso aos elementos via ponteiro
    }
    printf("\n");

    return 0;
}

