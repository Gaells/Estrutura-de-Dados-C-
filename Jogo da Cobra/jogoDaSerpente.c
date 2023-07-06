#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define WIDTH 80
#define HEIGHT 40

//// começo de gravação de resultados
#define MAX_RESULTADOS 5
#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    int pontos;
} Resultado;

typedef struct {
    Resultado resultados[MAX_RESULTADOS];
    int top;
} ResultadoStack;

void iniciaStack(ResultadoStack *stack) {
    stack->top = -1;
}

bool isStackVazio(ResultadoStack *stack) {
    return stack->top == -1;
}

bool isStackCheio(ResultadoStack *stack) {
    return stack->top == MAX_RESULTADOS - 1;
}

void push(ResultadoStack *stack, const char *nome, int pontos) {
    if (isStackCheio(stack)) {
        printf("A pilha de resultados esta cheia.\n");
        return;
    }

    Resultado newResultado;
    strncpy(newResultado.nome, nome, MAX_NOME);
    newResultado.pontos = pontos;

    stack->resultados[++stack->top] = newResultado;
}

Resultado pop(ResultadoStack *stack) {
    if (isStackVazio(stack)) {
        printf("A pilha de resultados esta vazia.\n");
        Resultado resultadoVazio = {"", 0};
        return resultadoVazio;
    }

    return stack->resultados[stack->top--];
}

void printStack(ResultadoStack *stack) {
    if (isStackVazio(stack)) {
        printf("A pilha de resultados esta vazia.\n");
        return;
    }

    printf("Top 5 Melhores Resultados:\n");
    printf("-------------------------\n");
    for (int i = stack->top; i >= 0; i--) {
        printf("%s - Pontos: %d\n", stack->resultados[i].nome, stack->resultados[i].pontos);
    }
}

void updateRecords(ResultadoStack *stack, const char *nome, int pontos) {
    if (isStackCheio(stack) && pontos <= stack->resultados[MAX_RESULTADOS - 1].pontos) {
        printf("Você não alcançou um dos melhores resultados.\n");
        return;
    }

    int i = stack->top;
    while (i >= 0 && pontos > stack->resultados[i].pontos) {
        i--;
    }

    i++;
    if (i < MAX_RESULTADOS) {
        Resultado newResultado;
        strncpy(newResultado.nome, nome, MAX_NOME);
        newResultado.pontos = pontos;

        for (int j = stack->top; j >= i; j--) {
            stack->resultados[j + 1] = stack->resultados[j];
        }

        stack->resultados[i] = newResultado;

        if (isStackCheio(stack)) {
            stack->top--;
        }

        push(stack, nome, pontos);
    }

    printf("Seu resultado foi registrado nos melhores resultados!\n");
}
//// término parte de gravação de resultados

enum Direction {
    STOP,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

enum Direction dir;
bool gameOver = false;

int cobraX, cobraY;
int pontos, cobraX = 0;

int caldaX[100], caldaY[100];
int nTail = 0;

struct Comida {
    int x;
    int y;
};

struct Comida comidas[20];
int comidas_consumidas = 0;

typedef struct {
    int pontos;
    struct tm time;
} Result;

// Função para criar o tabuleiro
void criaCampo() {
    for (int i = 0; i < 20; i++) {
        comidas[i].x = rand() % WIDTH;
        comidas[i].y = rand() % HEIGHT;
    }

    dir = STOP;
    pontos = 0;
    nTail = 0;
    gameOver = false;
}

void atualizaCampo() {
    system("cls");
    for (int i = 0; i < WIDTH + 2; i++) {
        printf("#");
    }
    printf("\n");

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (j == 0) {
                printf("#");
            }

            if (i == cobraY && j == cobraX) {
                printf("O");
            } else {
                bool printed = false;
                for (int k = 0; k < nTail; k++) {
                    if (caldaX[k] == j && caldaY[k] == i) {
                        printf("*");
                        printed = true;
                    }
                }
                for (int k = 0; k < 20; k++) {
                    if (comidas[k].x == j && comidas[k].y == i) {
                        printf("F");
                        printed = true;
                    }
                }
                if (!printed) {
                    printf(" ");
                }
            }

            if (j == WIDTH - 1) {
                printf("#");
            }
        }
        printf("\n");
    }

    for (int i = 0; i < WIDTH + 2; i++) {
        printf("#");
    }
    printf("\n");
    printf("pontos: %d\n", pontos);
}

int Velocidade = 300;  // Velocidade padrão
void changeVelocidade(int* currentVelocidade) {
    int newVelocidade;
    printf("Digite a nova velocidade de avanço da cobra: ");
    printf("\n1 - 100ms.");
    printf("\n2 - 200ms.");
    printf("\n3 - 300ms.");
    printf("\n4 - 400ms.");
    printf("\n5 - 500ms.\n");
    scanf("%d", &newVelocidade);
    
    switch (newVelocidade) {
        case 1:
            *currentVelocidade = 100;
            break;
        case 2:
            *currentVelocidade = 200;
            break;
        case 3:
            *currentVelocidade = 300;
            break;
        case 4:
            *currentVelocidade = 400;
            break;
        case 5:
            *currentVelocidade = 500;
            break;
        default:
            printf("Opcao invalida! Tente novamente.\n");
            return;
    }

    printf("Velocidade alterada para %dms\n", *currentVelocidade);
}

void updateSnake() {
    if (_kbhit()) {
        switch (_getch()) {
             case 'j':
                if (dir != RIGHT) 
                    dir = LEFT;
                break;
            case 'l':
                if (dir != LEFT) 
                    dir = RIGHT;
                break;
            case 'i':
                if (dir != DOWN) 
                    dir = UP;
                break;
            case 'k':
                if (dir != UP) 
                    dir = DOWN;
                break;
            case 'x':
                gameOver = true;
                break;
        }
    }

    int prevX = caldaX[0];
    int prevY = caldaY[0];
    int prev2X, prev2Y;
    caldaX[0] = cobraX;
    caldaY[0] = cobraY;
    for (int i = 1; i < nTail; i++) {
        prev2X = caldaX[i];
        prev2Y = caldaY[i];
        caldaX[i] = prevX;
        caldaY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir) {
        case LEFT:
            cobraX--;
            break;
        case RIGHT:
            cobraX++;
            break;
        case UP:
            cobraY--;
            if (cobraY < 0) {
                cobraY = HEIGHT - 1; 
            }
            break;
        case DOWN:
            cobraY++;
            if (cobraY >= HEIGHT) {
                cobraY = 0; 
            }
            break;
        default:
            break;
    }

    if (cobraX >= WIDTH) {
        cobraX = 0;
    } else if (cobraX < 0) {
        cobraX = WIDTH - 1;
    }

    for (int i = 0; i < 20; i++) {
        if (comidas[i].x != -1 && cobraX == comidas[i].x && cobraY == comidas[i].y) {
            pontos += 10;
            nTail++;
            caldaX[nTail - 1] = cobraX;
            caldaY[nTail - 1] = cobraY;
            comidas[i].x = -1;
            comidas[i].y = -1;
            comidas_consumidas++;

            if (comidas_consumidas == 20) {
                gameOver = true;
                printf("Parabens! Voce comeu todas as comidas!\n");
            }
        }
    }

    Sleep(Velocidade);
}

int main() {
    int escolha;
    ResultadoStack stack;
    iniciaStack(&stack);

    do {
        printf("\n==================================MENU================================:\n");
        printf("1- Iniciar Novo Jogo\n");
        printf("2- Alterar a velocidade de avanco da cobra\n");
        printf("3- Listar os melhores tempos (recordes)\n");
        printf("4- Sair do programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                criaCampo();
                while (!gameOver) {
                atualizaCampo();
                updateSnake();
                
				if (gameOver) {
    				char nome[MAX_NOME];
    				printf("Digite o seu nome: ");
    				scanf("%s", nome);

    				updateRecords(&stack, nome, pontos);
    				printf("Pressione qualquer tecla para continuar...");
    				_getch();
				}}
                break;
            case 2:
                changeVelocidade(&Velocidade);
                break;
            case 3:
                printStack(&stack);
                break;
            case 4:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    } while (escolha != 4);

    return 0;
}


