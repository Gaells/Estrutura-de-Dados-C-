#include <stdio.h>

#define LINHAS 3
#define COLUNAS 3

int main() {
    float matriz[LINHAS][COLUNAS] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
    float *ponteiro_matriz = &matriz[0][0]; // ponteiro para o início da matriz

    // percorrendo a matriz com o ponteiro e imprimindo o endereço e o valor de cada posição
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("Endereço: %p, Valor: %.2f\n", ponteiro_matriz, *ponteiro_matriz);
            ponteiro_matriz++; // avançando o ponteiro para a próxima posição
        }
    }

    return 0;
}

