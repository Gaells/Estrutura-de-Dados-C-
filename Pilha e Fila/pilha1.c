#include <stdio.h>
#include <stdlib.h>

int pilha[20];

int topo = -1;

void push(int valor){       
	topo++;       
	if(topo > -1 && topo < 20)            
		pilha[topo] = valor;       
	else        
	printf("A pilha está cheia!!!!"); 
};


int pop(){       
	if(topo < 0){            
	printf("A pilha está vazia!!!!");            
	return 9999;       
}return pilha[topo--];       
};

int size(){        
	return topo;        
};

int stackpop(){
    return pilha[topo];
};

void main(){
	printf("\nSao colocados dados na pilha");
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	push(6);
	
	printf("\nTamanho da pilha: %d", size());       
	printf("\nRetirando dado da pilha: %d", pop());       
	printf("\nRetirando dado da pilha: %d", pop());       
	printf("\nRetirando dado da pilha: %d", pop());       
	printf("\nTamanho da pilha: %d", size());       
	printf("\nAtual topo da pilha: %d", stackpop());       
	
	
	push(10);       
	printf("\nRetirando dado da pilha: %d", pop());       
	printf("\nRetirando dado da pilha: %d", pop());       
	printf("\nTamanho da pilha: %d", size());
	printf("\nAtual topo da pilha: %d", stackpop());
};

