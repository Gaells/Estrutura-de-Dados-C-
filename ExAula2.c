#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10

typedef struct {
    int *dados;
    int inicio, fim;
} Lista;

int inserir(Lista *L, int dado) {
    if (L->fim < TAMANHO) {
        L->dados[L->fim] = dado;
        (L->fim)++;
        return 1;
    }
    return 0;
}

int inserir_inicio(Lista *L, int dado) {
    int i;
    if (L->fim < TAMANHO) {
        for (i = L->fim; i > 0; i--) {
            L->dados[i] = L->dados[i-1];
        }
        L->dados[0] = dado;
        (L->fim)++;
        return 1;
    }
    return 0;
}

int remover(Lista *L, int indice) {
    int i;
    if ((indice >= 0) && (indice < L->fim)) {
        for (i = indice; i < L->fim-1; i++) {
            L->dados[i] = L->dados[i+1];
        }
        (L->fim)--;
        return 1;
    }
    return 0;
}

int acha_vetor(Lista *L, int dado, int *indice) {
    int i, achou = 0;
    for (i = 0; i < L->fim; i++) {
        if (L->dados[i] == dado) {
            *indice = i;
            achou = 1;
        }
    }
    return achou;
}

int lerSemScanf() {
    char input[100];  
    printf("Enter an integer:\n");
    fgets(input, sizeof(input), stdin);
    return strtol(input, NULL, 10);
}

int main() {
    int i, valor, procura;
    Lista s;
    s.dados = (int *) malloc(TAMANHO * sizeof(int));
    s.inicio = 0;
    s.fim = 0;

    int valores[] = {10, 20, 30, 40, 50};
	for (int i = 0; i < 5; i++) {
    	inserir(&s, valores[i]);
}

	
	printf("\nTodos os valores da lista");
	for(i=0; i<=s.fim-1; i++){
		printf("\n%d", s.dados[i]);
	}
	
	printf("\nLista apos inserir 60");
	inserir(&s, 60);
	
	for(i=0; i<=s.fim-1; i++){
		printf("\n%d", s.dados[i]);
	}
	
	printf("\nDigite um numero para inserir no inicio da lista: ");
	scanf("%d", &valor);
	inserir_inicio(&s, valor);
	
	for(i=0; i<=s.fim-1; i++){
		printf("\n%d", s.dados[i]);
	}
	
	printf("\nDigite um numero para procurar na lista: ");
	scanf("%d", &valor);
	if(acha_vetor(&s, valor, &procura))
		if((procura == 0) && (valor != s.dados[0])){
			printf("\nO valor nao foi encontrado.");
		}
		else
		printf("\nO valor esta no indice %d.", procura);		
	
	return 0;
}
