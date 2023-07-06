#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo_Pilha{                
	int elemento;                
	struct Nodo_Pilha *prox;       
}*NODOPTR; 

NODOPTR pilha = NULL; 

Cria_Nodo() {       
NODOPTR p;       
p = (NODOPTR) malloc(sizeof(struct Nodo_Pilha));       
if(!p){               
printf("Problemas na Alocação!!!");                
exit(0);       
	} 
	return p; 
};

void push(int dado) 
{       
NODOPTR nodo;       
nodo= Cria_Nodo( );       
nodo->elemento = dado;       
nodo->prox = pilha;      
pilha = nodo; 
}

int pop( ) {       
NODOPTR nodo;       
int elem;        
if(!pilha)        
{              
printf("A pilha está vazia!!!");              
return -1;        
}         
nodo = pilha;         
elem = nodo->elemento;         
pilha = nodo->prox;         
free(nodo);         
return elem; 
};

void main() {      
printf("São inseridos dados na pilha:");      
push(1);      
push(2);      
printf("\nRetira dado da pilha: %d", pop( ));      
printf("\nRetira dado da pilha: %d", pop( )); 
};

