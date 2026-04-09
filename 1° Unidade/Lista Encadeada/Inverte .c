#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    int valor;
    struct Node *next;
}Node;

void Inverte(Node **Head){
    Node *aux = *Head;
    Node *ant=NULL;
    Node *prox=NULL;
    while (aux!= NULL){
        prox=aux->next;
        aux->next=ant;
        ant=aux;
        aux=prox;
    }
    *Head=ant;
}


void push(Node **Head, int valor) {
    Node *novo = malloc(sizeof(Node));
    novo->valor = valor;
    novo->next = *Head;
    *Head = novo;
}

// Função para imprimir lista
void printList(Node *Head) {
    while (Head) {
        printf(" %d -> ", Head->valor);
        Head = Head->next;
    }
    printf("NULL\n");
}

int main() {

    Node *Head = NULL;

    // cria lista 1->2->3->4->5
    for (int i = 6; i >= 1; i--){
        push(&Head, i);

    }
    printList(Head);
    Inverte(&Head);
    printf("\n");
    printList(Head);
    return 0;
}