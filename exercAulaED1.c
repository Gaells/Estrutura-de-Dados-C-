#include <stdio.h>
#include <ctype.h>

#define FRASES 5
#define MAXFRASETAMANHO 40

int main() {
    char nome_arquivo[50];
    FILE *arquivo;
    int tam_frase;

     /* Le um nome para o arquivo a ser aberto: */      
	 printf("\n\n Entre com um nome para o arquivo:\n");
	 	scanf("%s", nome_arquivo);              
	 
	 if (!(arquivo = fopen(nome_arquivo,"w")))  
	 /* Caso ocorra algum erro na abertura do arquivo..*/  /* o programa aborta automaticamente */      
	{                                       
	 	printf("Erro! Impossivel abrir o arquivo!\n");             
		exit(1);         
	} 
		
    for (int i = 0; i < FRASES; i++) {
        char frase[MAXFRASETAMANHO+1]; 
        char c;

        printf("Digite a frase %d (maximo %d caracteres): ", i+1, MAXFRASETAMANHO);
        scanf(" %[^\n]", frase); 

        tam_frase = 0;
        while (frase[tam_frase] != '\0') { 
            c = frase[tam_frase];
            frase[tam_frase] = toupper(c); 
            tam_frase++;
        }

        fwrite(&tam_frase, sizeof(int), 1, arquivo); 
        fwrite(frase, sizeof(char), tam_frase, arquivo); 
    }

    fclose(arquivo);

    arquivo = fopen(nome_arquivo,"r");
    printf("\nAs frases gravadas no arquivo sao:\n");

    for (int i = 0; i < FRASES; i++) {
        char frase[MAXFRASETAMANHO+1];

        fread(&tam_frase, sizeof(int), 1, arquivo);
        fread(frase, sizeof(char), tam_frase, arquivo);
        frase[tam_frase] = '\0';

        printf("%d) %s\n", i+1, frase);
    }

    fclose(arquivo);

    return 0;
}
