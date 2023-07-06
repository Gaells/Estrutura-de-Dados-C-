/* 
2 - Crie um vetor que tenha tamanho suficiente para acomodar todas as letras do seu nome completo (n�o precisa considerar os espa�os entre os nomes);

A partir do programa acima (use-o como base de partida) realize uma busca bin�ria, 
ou seja, ser� necess�rio primeiro ordenar o vetor (deve ser o m�todo insertion sort) 
e a seguir utilize o algoritmo de busca bin�ria para encontrar as letras conforme a entrada feita pelo teclado (ex: scanf());

Fa�a tamb�m o teste de busca com uma letra que n�o exista no seu nome. 
Seu programa dever� imprimir o valor -1. 
Apresente um print desta condi��o;
*/

#include <stdio.h>
#include <ctype.h>

// Fun��o de busca_binaria
int busca_binaria(char VET[], char CHAVE, int tamanho, int resultados[]) {
    int INIC = 0;
    int FINAL = tamanho - 1;
    int METADE;
    int contador = 0;

    do {
        METADE = (INIC + FINAL) / 2;
        if (CHAVE < VET[METADE]) {
            FINAL = METADE - 1;
        } else {
            INIC = METADE + 1;
        }
    } while (VET[METADE] != CHAVE && INIC <= FINAL);

    if (VET[METADE] == CHAVE) {
        // Armazena o �ndice encontrado no vetor resultados
        resultados[contador] = METADE;
        contador++;

        // Verifica se h� outros caracteres iguais � esquerda
        int i = METADE - 1;
        while (i >= 0 && VET[i] == CHAVE) {
            resultados[contador] = i;
            contador++;
            i--;
        }

        // Verifica se h� outros caracteres iguais � direita
        i = METADE + 1;
        while (i < tamanho && VET[i] == CHAVE) {
            resultados[contador] = i;
            contador++;
            i++;
        }

        return contador; // Retorna a quantidade de ocorr�ncias encontradas
    } else {
        return -1; // Letra n�o encontrada
    }
}

// Fun��o insertion_sort
void insertion_sort(char VET[], int tamanho) {
    int i, j;
    char chave;

    for (i = 1; i < tamanho; i++) {
        chave = VET[i];
        j = i - 1;

        while (j >= 0 && VET[j] > chave) {
            VET[j + 1] = VET[j];
            j = j - 1;
        }

        VET[j + 1] = chave;
    }
}

int main() {
    char vetNome[24] = {'G', 'A', 'B', 'R', 'I', 'E', 'L', 'C', 'H', 'I', 'O', 'Q', 'U', 'E', 'T', 'T', 'A', 'O', 'B', 'L', 'A', 'D', 'E', 'N'};
    int tamanho = sizeof(vetNome) / sizeof(vetNome[0]);
    int resultados[24]; // Vetor para armazenar os �ndices das ocorr�ncias

    insertion_sort(vetNome, tamanho);

    printf("\nOs valores depois da Ordena�ao por InsertionSort sao:\n");
    for (int x = 0; x < tamanho; x++) {
        printf("%c ", vetNome[x]);
    }

    printf("\n\nDigite a letra que deseja buscar:\n ");
    char letra;
    scanf(" %c", &letra);

    // Converter a letra para mai�scula
    letra = toupper(letra);

    int quantidade = busca_binaria(vetNome, letra, tamanho, resultados);

    if (quantidade != -1) {
        printf("\n\nA letra '%c' foi encontrada em %d posi�ao(s):\n", letra, quantidade);
        for (int i = 0; i < quantidade; i++) {
            printf("Indice: %d\n", resultados[i]);
        }
    } else {
        printf("\nA letra '%c' n�o foi encontrada! Valor: %d\n", letra, quantidade);
    }

    return 0;
}

