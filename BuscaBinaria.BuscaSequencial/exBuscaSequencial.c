/* 
1 - Fa�a um programa em linguagem C que use o m�todo de busca sequencial para encontrar e imprimir o seguinte resultado:

Dados:
Crie um vetor que tenha tamanho suficiente para acomodar todas as letras do seu nome completo (n�o precisa considerar os espa�os entre os nomes);
Fa�a uma busca sequencial para identificar quais as posi��es do vetor possuem a letra A; 
Fa�a um print do �ndice da posi��o (ou posi��es);
Fa�a o teste de busca com uma letra que n�o exista no seu nome. 
Seu programa dever� imprimir o valor -1. 
Apresente um print desta condi��o;
*/
#include <stdio.h>
#include <ctype.h>

// Fun��o de busca sequencial
void buscaSequencial(char VET[], int tamanho, char chave) {
    int i;
    int encontrou = 0; // Vari�vel para verificar se a chave foi encontrada

    printf("Indice(s) da letra '%c': ", chave);
    for (i = 0; i < tamanho; i++) {
        if (VET[i] == chave) {
            printf("%d ", i);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("-1"); // Chave n�o encontrada
    }
}

int main() {
    char vetNome[24] = {'G', 'A', 'B', 'R', 'I', 'E', 'L', 'C', 'H', 'I', 'O', 'Q', 'U', 'E', 'T', 'T', 'A', 'O', 'B', 'L', 'A', 'D', 'E', 'N'};
    int tamanho = sizeof(vetNome) / sizeof(vetNome[0]);

    printf("Vetor do Nome: ");
    for (int x = 0; x < tamanho; x++) {
        printf("%c ", vetNome[x]);
    }

    printf("\n\nBuscando ocorrencias da letra 'A':\n\n");
    buscaSequencial(vetNome, tamanho, 'A');
    
    printf("\n\nTestando busca com uma letra inexistente:\n");
    buscaSequencial(vetNome, tamanho, 'Z');

    return 0;
}



