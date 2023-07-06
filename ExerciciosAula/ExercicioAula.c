#include <stdio.h>
#include <ctype.h> // biblioteca necessária para utilizar a função toupper()

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
        char frase[MAXFRASETAMANHO+1]; // +1 para incluir o caractere nulo ao final da string
        char c;

        printf("Digite a frase %d (maximo %d caracteres): ", i+1, MAXFRASETAMANHO);
        scanf(" %[^\n]", frase); // lendo a frase com espaços em branco e sem incluir o '\n'

        tam_frase = 0;
        while (frase[tam_frase] != '\0') { // percorrendo a string até o final
            c = frase[tam_frase];
            frase[tam_frase] = toupper(c); // convertendo para maiúscula
            tam_frase++;
        }

        fwrite(&tam_frase, sizeof(int), 1, arquivo); // escrevendo o tamanho da frase no arquivo
        fwrite(frase, sizeof(char), tam_frase, arquivo); // escrevendo a frase no arquivo
    }

    fclose(arquivo); // fechando o arquivo de escrita

    arquivo = fopen(nome_arquivo,"r");
    printf("\nAs frases gravadas no arquivo sao:\n");

    for (int i = 0; i < FRASES; i++) {
        char frase[MAXFRASETAMANHO+1]; // +1 para incluir o caractere nulo ao final da string

        fread(&tam_frase, sizeof(int), 1, arquivo); // lendo o tamanho da frase do arquivo
        fread(frase, sizeof(char), tam_frase, arquivo); // lendo a frase do arquivo
        frase[tam_frase] = '\0'; // adicionando o caractere nulo ao final da string

        printf("%d) %s\n", i+1, frase); // imprimindo a frase
    }

    fclose(arquivo); // fechando o arquivo de leitura

    return 0;
}

