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

int SomaPares(Node *Head){
    int soma = 0;
    while(Head!=NULL){
        if(Head->valor%2==0)
            soma+=Head->valor;
        Head=Head->next;
    }
    return soma;
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
    for (int i = 5; i >= 1; i--)
        push(&Head, i);

       printf("%d", SomaPares(Head));
    return 0;
}