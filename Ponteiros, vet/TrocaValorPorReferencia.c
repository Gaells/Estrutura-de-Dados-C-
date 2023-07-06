#include <stdio.h>
#include <stdlib.h>

void troca(int x, int y){
	
	int temp; // variavel temporaria para salvar o valor de x
	temp = x;
	x = y;
	y = temp;
	
	printf("O valor de x em troca(): %d \n", x);
	printf("O valor de y em troca(): %d \n", y);
	
}

int main(){
	
	int a = 5;
	int b = 10;
	
	printf("O valor de a antes da troca: %d \n", a);
	printf("O valor de b antes da troca: %d \n", b);
	
	
	troca(a, b);
	
	printf("O valor de a depois da troca: %d \n", a);
	printf("O valor de b depois da troca: %d \n", b);
	
	return 0;
}
