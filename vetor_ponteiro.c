
#include <stdio.h>

int main() {
  int numeros[5] = {10, 20, 30, 40, 50}; // declara��o e inicializa��o de um vetor de inteiros
  int *ptr;                            // declara��o de um ponteiro para um inteiro
  ptr = numeros;                       // atribui o endere�o do primeiro elemento do vetor ao ponteiro

  printf("Elementos do vetor usando �ndices:\n");
  for (int i = 0; i < 5; i++) {
    printf("%d ", numeros[i]); // acesso aos elementos do vetor usando �ndices
  }

  printf("\nElementos do vetor usando ponteiro:\n");
  for (int i = 0; i < 5; i++) {
    printf("%d ", *(ptr + i)); // acesso aos elementos do vetor usando ponteiro
  }

  return 0;
}


