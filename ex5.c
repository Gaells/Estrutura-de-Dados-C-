#include <stdio.h>

#define TAMANHO_ARRAY 5

int main() {
    int array[TAMANHO_ARRAY];
    int *ponteiro_array = array; // ponteiro para o in�cio do array

    // leitura dos valores do array via teclado
    for (int i = 0; i < TAMANHO_ARRAY; i++) {
        printf("Digite o valor para o elemento %d: ", i);
        scanf("%d", ponteiro_array+i); // leitura via ponteiro
    }

    // impress�o dos endere�os das posi��es contendo valores pares
    printf("Posi��es contendo valores pares:\n");
    for (int i = 0; i < TAMANHO_ARRAY; i++) {
        if (*(ponteiro_array+i) % 2 == 0) { // verifica��o se o valor � par
            printf("%p\n", (ponteiro_array+i)); // impress�o do endere�o via ponteiro
        }
    }

    return 0;
}

