#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    int valor;
    struct Node *next;
}Node;

void TrocaCelula(Node **Head, int n1, int n2){
    Node *aux1 = (*Head);
    Node *aux2 = (*Head);
    Node *ant1 = NULL;
    Node *ant2 = NULL;
if(!(n1 == n2)){
    while(aux1 && aux1->valor!= n1){
        ant1=aux1;
        aux1= aux1->next;
    }
    while(aux2 && aux2->valor != n2){
        ant2 = aux2;
        aux2 = aux2->next;
    }

    if(!aux1 || !aux2)return;

    if(ant1!=NULL)
        ant1->next = aux2;
    else
        (*Head) = aux2;
    if(ant2 != NULL)
        ant2->next = aux1;
    else
        (*Head) = aux1;
    
    Node *temp = aux1->next;
    aux1->next = aux2->next;
    aux2->next = temp;

}
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
    for (int i = 5; i >= 1; i--)
        push(&Head, i);

    printf("Lista original:\n");
    printList(Head);
TrocaCelula(&Head, 3, 5);

    printf(" Lista após trocar 2 e 4:\n");
    printList(Head);

    return 0;
}
