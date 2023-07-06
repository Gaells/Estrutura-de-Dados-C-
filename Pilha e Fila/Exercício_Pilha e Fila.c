#include <stdio.h>
#include <stdlib.h>

struct Elemento_pilha {
	int num;
	struct Elemento_pilha* prox;
};

typedef struct Elemento_pilha Elemento_pilha;

struct Pilha {
	struct Elemento_pilha* topo;
};

typedef struct Pilha Pilha;

struct Elemento_fila {
	int num;
	struct Elemento_fila* prox;
};

typedef struct Elemento_fila Elemento_fila;

struct Fila {
	struct Elemento_fila* inicio;
	struct Elemento_fila* fim;
};

typedef struct Fila Fila;

Pilha* cria_pilha() {
	Pilha* pi = (Pilha*)malloc(sizeof(Pilha));
	if (pi != NULL) {
		pi->topo = NULL;
	}
	return pi;
}

Fila* cria_fila() {
	Fila* fi = (Fila*)malloc(sizeof(Fila));
	if (fi != NULL) {
		fi->fim = NULL;
		fi->inicio = NULL;
	}
	return fi;
}

void insere_elemento_pilha(Pilha* pi, int numero) {
	Elemento_pilha* novo = (Elemento_pilha*)malloc(sizeof(Elemento_pilha));
	novo->num = numero;
	novo->prox = pi->topo;
	pi->topo = novo;
}

void insere_elemento_fila(Fila* fi, int numero) {
	Elemento_fila* novo = (Elemento_fila*)malloc(sizeof(Elemento_fila));
	novo->num = numero;
	novo->prox = NULL;
	if (fi->inicio == NULL) {
		fi->inicio = novo;
		fi->fim = novo;
	}
	else {
		fi->fim->prox = novo;
		fi->fim = novo;
	}
}

void copia_fila_para_pilha(Fila* fi, Pilha* pi) {
	Elemento_fila* atual = fi->inicio;
	while (atual != NULL) {
		insere_elemento_pilha(pi, atual->num);
		atual = atual->prox;
	}
}

void exibe_pilha(Pilha* pi) {
	Elemento_pilha* atual = pi->topo;
	while (atual != NULL) {
		printf("%d ", atual->num);
		atual = atual->prox;
	}
	printf("\n");
}

void libera_pilha(Pilha* pi) {
	Elemento_pilha* atual = pi->topo;
	while (atual != NULL) {
		Elemento_pilha* temp = atual;
		atual = atual->prox;
		free(temp);
	}
	free(pi);
}

void libera_fila(Fila* fi) {
	Elemento_fila* atual = fi->inicio;
	while (atual != NULL) {
		Elemento_fila* temp = atual;
		atual = atual->prox;
		free(temp);
	}
	free(fi);
}

int main() {
	Fila* fila = cria_fila();
	Pilha* pilha = cria_pilha();

	// Inserindo números na fila
	printf("Insira 5 numeros na fila:\n");
	for (int i = 0; i < 5; i++) {
		int num;
		scanf("%d", &num);
		insere_elemento_fila(fila, num);
	}

	// Copiando os números da fila para a pilha
	copia_fila_para_pilha(fila, pilha);

	printf("Pilha: ");
	exibe_pilha(pilha);

	libera_fila(fila);
	libera_pilha(pilha);
};
