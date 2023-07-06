/* 
2 - Crie um vetor que tenha tamanho suficiente para acomodar todas as letras do seu nome completo (não precisa considerar os espaços entre os nomes);

A partir do programa acima (use-o como base de partida) realize uma busca binária, 
ou seja, será necessário primeiro ordenar o vetor (deve ser o método insertion sort) 
e a seguir utilize o algoritmo de busca binária para encontrar as letras conforme a entrada feita pelo teclado (ex: scanf());

Faça também o teste de busca com uma letra que não exista no seu nome. 
Seu programa deverá imprimir o valor -1. 
Apresente um print desta condição;
*/

#include <stdio.h>
#include <ctype.h>

// Função de busca_binaria
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
        // Armazena o índice encontrado no vetor resultados
        resultados[contador] = METADE;
        contador++;

        // Verifica se há outros caracteres iguais à esquerda
        int i = METADE - 1;
        while (i >= 0 && VET[i] == CHAVE) {
            resultados[contador] = i;
            contador++;
            i--;
        }

        // Verifica se há outros caracteres iguais à direita
        i = METADE + 1;
        while (i < tamanho && VET[i] == CHAVE) {
            resultados[contador] = i;
            contador++;
            i++;
        }

        return contador; // Retorna a quantidade de ocorrências encontradas
    } else {
        return -1; // Letra não encontrada
    }
}

// Função insertion_sort
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
    int resultados[24]; // Vetor para armazenar os índices das ocorrências

    insertion_sort(vetNome, tamanho);

    printf("\nOs valores depois da Ordenaçao por InsertionSort sao:\n");
    for (int x = 0; x < tamanho; x++) {
        printf("%c ", vetNome[x]);
    }

    printf("\n\nDigite a letra que deseja buscar:\n ");
    char letra;
    scanf(" %c", &letra);

    // Converter a letra para maiúscula
    letra = toupper(letra);

    int quantidade = busca_binaria(vetNome, letra, tamanho, resultados);

    if (quantidade != -1) {
        printf("\n\nA letra '%c' foi encontrada em %d posiçao(s):\n", letra, quantidade);
        for (int i = 0; i < quantidade; i++) {
            printf("Indice: %d\n", resultados[i]);
        }
    } else {
        printf("\nA letra '%c' não foi encontrada! Valor: %d\n", letra, quantidade);
    }

    return 0;
}

