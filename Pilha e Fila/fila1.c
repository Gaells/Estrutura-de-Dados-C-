#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo_Fila {
    int elemento;
    struct Nodo_Fila *prox;
} *NODOPTR;

NODOPTR fila = NULL;

NODOPTR Cria_Nodo(int dado) {
    NODOPTR p;
    p = (NODOPTR) malloc(sizeof(struct Nodo_Fila));
    if (!p) {
        printf("Problemas na Alocação!!!");
        exit(0);
    }
    p->elemento = dado;
    p->prox = NULL;
    return p;
}

void push(int dado) {
    NODOPTR nodo;
    nodo = Cria_Nodo(dado);
    nodo->prox = fila;
    fila = nodo;
}

int pop() {
    NODOPTR nodo;
    int elem;
    if (!fila) {
        printf("A fila esta vazia!!!");
        return -1;
    }
    nodo = fila;
    elem = nodo->elemento;
    fila = nodo->prox;
    free(nodo);
    return elem;
}

void insere_lista(int dado) {
    push(dado);
}

int remove_lista() {
    return pop();
}

int main() {
    int dado;
    printf("Insira 3 numeros inteiros para serem adicionados a fila:\n");
    for (int i = 0; i < 3; i++) {
        scanf("%d", &dado);
        insere_lista(dado);
    }
    printf("Removidos da fila: %d %d %d\n", remove_lista(), remove_lista(), remove_lista());
    return 0;
}

