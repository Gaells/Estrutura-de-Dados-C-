#include <stdio.h>
#include <stdlib.h>

typedef struct item {
    int data;
    struct item *next;
} listItem;

// Aloca memoria para um item da lista
listItem *itemCreate() {
    listItem *p;
    p = (listItem *) malloc(sizeof(listItem));
    p->next = NULL;

    if (!p) {
        printf("Problema ao criar/alocar novo item.");
        exit(0);
    }
    return p;
}

// Insere elemento no inicio da lista
/*void insertStart(listItem *init, int info) {
    listItem *newListItem;
    newListItem = itemCreate();
    newListItem->data = info;
    newListItem->next = init->next;
    init->next = newListItem;
*/

// Insere elemento no final da lista
void insertEnd(listItem *init, int info) {
    listItem *newListItem;
    newListItem = itemCreate();
    newListItem->data = info;
    newListItem->next = NULL;
    
    if (init->next == NULL) {
        init->next = newListItem;
    } else {
        listItem *listPointer = init->next;
        while (listPointer->next != NULL) {
            listPointer = listPointer->next;
        }
        listPointer->next = newListItem;
    }
}

//exlcuindo item da lista
void excluiItem(listItem *listPointer){
        
}

// imprime a lista
void printList(listItem *listPointer) {
    while (listPointer != NULL) {
        printf("%d ", listPointer->data);
        listPointer = listPointer->next;
    }
    printf("\n");
}

int main(void) {
    listItem *listInit;
    listInit = itemCreate();

    int info;

    for (int i = 0; i < 3; i++) {
        printf("Entre com o valor do novo no: ");
        scanf("%d", &info);
        insertEnd(listInit, info);
    }

    printList(listInit);

    // Percorre a lista
    listItem *listPointer = listInit->next;
    while (listPointer != NULL) {
        printf("%d\n", listPointer->data);
        listPointer = listPointer->next;
    }

    // Acha um valor na lista
    int achei = 0;
    listPointer = listInit->next;
    while (listPointer != NULL) {
        if (listPointer->data == 12) {
            printf("ACHEEEEI SAFADO %d\n", listPointer->data);
            achei = 1;
            break;
        }
        listPointer = listPointer->next;
    }
    if (achei == 0) {
        printf("Nao achei\n");
    }
    return 0;
}
