#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
    Node* tail;
} LinkedList;

LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void insertAtHead(LinkedList* list, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = list->tail;
    newNode->next = list->head;
    
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->head->prev = newNode;
        list->tail->next = newNode;
        list->head = newNode;
    }
}

void insertAtTail(LinkedList* list, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = list->tail;
    newNode->next = list->head;
    
    if (list->tail == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->head->prev = newNode;
        list->tail = newNode;
    }
}

void removeFromHead(LinkedList* list) {
    if (list->head == NULL) {
        return;
    }
    
    Node* nodeToRemove = list->head;
    list->head = nodeToRemove->next;
    list->tail->next = list->head;
    list->head->prev = list->tail;
    free(nodeToRemove);
}

void removeFromTail(LinkedList* list) {
    if (list->tail == NULL) {
        return;
    }
    
    Node* nodeToRemove = list->tail;
    list->tail = nodeToRemove->prev;
    list->tail->next = list->head;
    list->head->prev = list->tail;
    free(nodeToRemove);
}

void printList(LinkedList* list) {
    if (list->head == NULL) {
        return;
    }
    
    Node* currentNode = list->head;
    printf("%d ", currentNode->data);
    
    while (currentNode->next != list->head) {
        currentNode = currentNode->next;
        printf("%d ", currentNode->data);
    }
    
    printf("\n");
}

int main() {
    LinkedList* list = createLinkedList();
    
    insertAtHead(list, 3);
    insertAtHead(list, 2);
    insertAtHead(list, 1);
    
    insertAtTail(list, 4);
    insertAtTail(list, 5);
    
    printList(list);
    
    removeFromHead(list);
    removeFromTail(list);
    
    printList(list);
    
    return 0;
}

