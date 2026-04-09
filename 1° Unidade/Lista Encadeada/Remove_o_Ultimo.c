#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    int valor;
    struct Node *next;
}Node;



void push(Node **Head, int valor) {
    Node *novo = malloc(sizeof(Node));
    novo->valor = valor;
    novo->next = *Head;
    *Head = novo;
}

void RemoveUltimo(Node **Head) {
    if (*Head == NULL) return; // lista vazia

    Node *aux = *Head;
    Node *ant = NULL;

    // percorre até o último
    while (aux->next != NULL) {
        ant = aux;
        aux = aux->next;
    }

    if (ant == NULL) {
        // a lista só tinha 1 nó
        free(*Head);
        *Head = NULL;
    } else {
        // mais de 1 nó
        ant->next = NULL;
        free(aux);
    }
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
    for (int i = 5; i >= 1; i--){
        push(&Head, i);}
    
    printList(Head);
    
    RemoveUltimo(&Head);
    printList(Head);
    return 0;
}