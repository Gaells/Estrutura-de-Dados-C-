
#include <stdio.h>

int main() {
  int numeros[5] = {10, 20, 30, 40, 50}; // declaração e inicialização de um vetor de inteiros
  int *ptr;                            // declaração de um ponteiro para um inteiro
  ptr = numeros;                       // atribui o endereço do primeiro elemento do vetor ao ponteiro

  printf("Elementos do vetor usando índices:\n");
  for (int i = 0; i < 5; i++) {
    printf("%d ", numeros[i]); // acesso aos elementos do vetor usando índices
  }

  printf("\nElementos do vetor usando ponteiro:\n");
  for (int i = 0; i < 5; i++) {
    printf("%d ", *(ptr + i)); // acesso aos elementos do vetor usando ponteiro
  }

  return 0;
}


