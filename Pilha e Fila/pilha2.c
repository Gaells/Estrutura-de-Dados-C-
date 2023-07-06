#include <stdio.h>
#include <stdlib.h>
#define TAM 20

typedef struct{       
	int topo;       
	int pilha[TAM]; 
}Stack;

int empty(Stack p); 
//verifica se a pilha está vazia 
int pop(Stack *p); 
void push(Stack *p, int dado); 
int size(Stack p); 
int stackpop(Stack p);

int *pilha;
int *inicio=NULL, *fim=NULL;

int pop() {     
	pilha --;     
	if(pilha < inicio){          
		printf("Pilha Vazia!!!!");          
		return 9999;     
		}      
		return *pilha; 
}; 

void push(int dado){     
	if(pilha > fim){          
		printf("Pilha Cheia!!!!");          
		return;     
} *pilha = dado;      
   pilha++; 
} 

void main(){        
	int total_elem;        
	printf("\nInforme o tamanho máximo da pilha:");        
	scanf(“%d”, &total_elem);         
	pilha = (int *)malloc(sizeof(int) * total_elem);         
	if(!pilha){                
	printf("\nFalha na Alocação!!!");                
	exit(1);         
} inicio = pilha;         
  fim = pilha + (total_elem-1);         
  printf("São inseridos dados na pilha.");         
  push(1);         
  push(2);         
  printf("Retirando dado na pilha: %d", pop( ));         
  printf("Retirando dado na pilha: %d", pop( ));         
  free(pilha); 
} ;

