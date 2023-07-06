#include <stdio.h>
#include <stdlib.h>

#define MAXVETOR 100

typedef struct tipo_vetor {
    int dados[MAXVETOR];
    int fim;
} Tipo_Vetor;

typedef struct nodo {
    int dado;
    struct nodo *prox;
} Nodo;

int acha_vetor(Tipo_Vetor V, int dado, int *indice) {
    int i, achou = 0;

    for(i = 0; i < V.fim; i++) {
        if(V.dados[i] == dado) {
            *indice = i;
            achou = 1;
        }
    }

    if(achou)
        return 1;
    else
        return 0;
}

int exclui_vetor(Tipo_Vetor *V, int indice) {
    int i;

    if((indice >= 0) && (indice < MAXVETOR)) {
        for(i = indice; i < V->fim-1; i++) {
            V->dados[i] = V->dados[i+1];
        }

        (V->fim)--;

        return 1;
    } else {
        return 0;
    }
}

Nodo * Cria_Nodo() {
    Nodo *p;

    p = (Nodo *) malloc(sizeof(Nodo));

    if(!p) {
        printf("Problema de alocacao");
        exit(0);
    }

    return p;
}

void insere_inicio_lista(Nodo **N, int dado) {
    Nodo *novo;

    novo = Cria_Nodo();

    novo->dado = dado;
    novo->prox = *N;

    *N = novo;
}

void insere_fim_lista(Nodo **N, int dado) {
    Nodo *novo, *aux;

    novo = Cria_Nodo();

    novo->dado = dado;
    novo->prox = NULL;

    if(*N == NULL) {
        *N = novo;
    } else {
        aux = *N;

        while(aux->prox != NULL) {
            aux = aux->prox;
        }

        aux->prox = novo;
    }
}

int main() {
    Tipo_Vetor V;
    V.fim = 0;
    int indice, dado, i, n;

    printf("Digite a quantidade de valores que deseja inserir no vetor: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Digite o valor %d: ", i+1);
        scanf("%d", &dado);
        V.dados[i] = dado;
        V.fim++;
    }

    printf("Digite o valor que deseja buscar no vetor: ");
    scanf("%d", &dado);

    if(acha_vetor(V, dado, &indice)) {
        printf("Dado encontrado no indice %d\n", indice);
    } else {
        printf("Dado nao encontrado\n");
    }

    printf("Digite o indice do valor que deseja excluir do vetor: ");
    scanf("%d", &indice);

    if(exclui_vetor(&V, indice)) {
        printf("Elemento excluido com sucesso\n");
    } else {
        printf("Nao foi possivel excluir o elemento\n");
    }

    Nodo*lista = NULL;
    int opcao, valor;
    
do {
    printf("\n1 - Inserir no inicio da lista");
    printf("\n2 - Inserir no fim da lista");
    printf("\n3 - Sair");
    printf("\nDigite a opcao desejada: ");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:
            printf("\nDigite o valor a ser inserido: ");
            scanf("%d", &valor);
            insere_inicio_lista(&lista, valor);
            break;
        case 2:
            printf("\nDigite o valor a ser inserido: ");
            scanf("%d", &valor);
            insere_fim_lista(&lista, valor);
            break;
        case 3:
            break;
        default:
            printf("\nOpcao invalida, tente novamente");
    }
} while(opcao != 3);

Nodo *aux = lista;
printf("\nValores na lista: ");

while(aux != NULL) { 
    printf("%d ", aux->dado);
    aux = aux->prox;
    
}
printf("\n");

return 0;
}

