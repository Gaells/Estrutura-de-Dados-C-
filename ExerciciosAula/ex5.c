#include <stdio.h>

#define TAMANHO_ARRAY 5

int main() {
    int array[TAMANHO_ARRAY];
    int *ponteiro_array = array; // ponteiro para o início do array

    // leitura dos valores do array via teclado
    for (int i = 0; i < TAMANHO_ARRAY; i++) {
        printf("Digite o valor para o elemento %d: ", i);
        scanf("%d", ponteiro_array+i); // leitura via ponteiro
    }

    // impressão dos endereços das posições contendo valores pares
    printf("Posições contendo valores pares:\n");
    for (int i = 0; i < TAMANHO_ARRAY; i++) {
        if (*(ponteiro_array+i) % 2 == 0) { // verificação se o valor é par
            printf("%p\n", (ponteiro_array+i)); // impressão do endereço via ponteiro
        }
    }

    return 0;
}

