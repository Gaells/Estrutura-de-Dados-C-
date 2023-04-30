#include <stdio.h>

#define LINHAS 3
#define COLUNAS 3

int main() {
    float matriz[LINHAS][COLUNAS] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
    float *ponteiro_matriz = &matriz[0][0]; // ponteiro para o in�cio da matriz

    // percorrendo a matriz com o ponteiro e imprimindo o endere�o e o valor de cada posi��o
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("Endere�o: %p, Valor: %.2f\n", ponteiro_matriz, *ponteiro_matriz);
            ponteiro_matriz++; // avan�ando o ponteiro para a pr�xima posi��o
        }
    }

    return 0;
}

