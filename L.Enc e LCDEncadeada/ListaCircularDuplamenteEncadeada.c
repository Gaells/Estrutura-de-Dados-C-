#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct ListaEncadeada{
    Node *inicio;
    Node *fim;
} ListaEncadeada;

//Cria e inicializa Lista ECDC nova e vazia
ListaEncadeada *CriaListaEncadeada(){
    ListaEncadeada *lista = (ListaEncadeada*) malloc(sizeof(ListaEncadeada));
    lista->inicio = NULL;
    lista->fim = NULL;
    return lista;
}

void InsereNoInicio(ListaEncadeada *lista, int data){
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = lista->fim;
    newNode->next = lista->inicio;

    if(lista->inicio == NULL){
        lista->inicio = newNode;
        lista->fim = newNode;
    } else{
        lista->inicio->prev = newNode;
        lista->fim->next = newNode;
        lista->inicio = newNode;
    }
}

void printList(ListaEncadeada *lista) {
    if(lista->inicio == NULL) {
        printf("Lista vazia\n");
        return;
    }

    Node *noAtual = lista->inicio;
    printf("%d ", noAtual->data);

    while(noAtual->next != lista->inicio){
        noAtual = noAtual->next;
        printf("%d ", noAtual->data);
    }

    printf("\n");
}

int findDistance(ListaEncadeada *lista, int num1, int num2) {
    if (lista->inicio == NULL) {
        return -1;
    }

    Node *current = lista->inicio;
    int distance = 0;
    int minDistance = -1;

    do {
        if (current->data == num1) {
            Node *temp = current->next;
            while (temp != current) {
                distance++;
                if (temp->data == num2) {
                    if (minDistance == -1 || distance < minDistance) {
                        minDistance = distance;
                    }
                    break;
                }
                temp = temp->next;
            }
            distance = 0;
        }
        current = current->next;
    } while (current != lista->inicio);

    return minDistance;
}

void removeCopia(ListaEncadeada *lista) {
    if (lista->inicio == NULL) {
        return;
    }

    Node *current = lista->inicio;
    Node *temp = NULL;

    while (current != NULL && current->next != lista->inicio) {
        temp = current->next;
        while (temp != NULL && temp != lista->inicio) {
            if (current->data == temp->data) {
                Node *duplicate = temp;
                temp = temp->next;
                current->next = temp;
                free(duplicate);
            } else {
                temp = temp->next;
            }
        }
        current = current->next;
    }
}

int main() {
    ListaEncadeada *lista = CriaListaEncadeada();
    int value;

    for (int i = 0; i < 12; i++) {
        printf("Insira um numero inteiro: ");
        scanf("%d", &value);
        InsereNoInicio(lista, value);
    }

    printf("Lista original: ");
    printList(lista);

    int num1, num2;
    printf("Insira dois numeros existentes na lista: ");
    scanf("%d %d", &num1, &num2);

int distancia = findDistance(lista, num1, num2); //calcula a distância entre num1 e num2 na lista
if (distancia == -1) {
    printf("Pelo menos um dos numeros nao existe na lista.\n");
} else {
    printf("A menor distancia entre %d e %d eh %d.\n", num1, num2, distancia);
    printf("Caminho mais curto: ");

    if (num1 == num2) {
        printf("0\n");
    } else if (distancia == 1) {
        printf("%d\n", (num1 < num2) ? 1 : -1);
    } else {
        int rightDist = 0, leftDist = 0;
        Node *current = lista->inicio;

        do {
            if (current->data == num1) {
                Node *temp = current->next;
                while (temp != current) {
                    rightDist++;
                    if (temp->data == num2) {
                        printf("%d\n", rightDist);
                        return 0;
                    }
                    temp = temp->next;
                }
                rightDist = 0;
            } else if (current->data == num2) {
                Node *temp = current->next;
                while (temp != current) {
                    leftDist--;
                    if (temp->data == num1) {
                        printf("%d\n", leftDist);
                        return 0;
                    }
                    temp = temp->next;
                }
                leftDist = 0;
            }
            current = current->next;
        } while (current != lista->inicio);
    }
}

removeCopia(lista); //remove os elementos duplicados na lista

printf("Lista sem copias: ");
printList(lista);

return 0;
}
