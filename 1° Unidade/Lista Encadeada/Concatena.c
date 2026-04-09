// Escreva uma função que receba duas listas encadeadas de inteiros L1 e L2e
// concatene-as. Ao final desse processo, L1 conterá os elementos das duas
// listas e L2 estará vazia.

#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    int valor;
    struct Node *next;
}Node;

void Concatena(Node **L1, Node **L2){
    
    if(!*L1)
        *L1=*L2;

    else{
        Node *aux= (*L1);
        while(aux->next!= NULL)
            aux=aux->next;
        aux->next = *L2;
        
    }
    *L2=NULL;
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
    Node *L1 = NULL;
    Node *L2 = NULL;

    // cria lista 1->2->3->4->5
    for (int i = 3; i >= 1; i--){
        push(&L1, i*2);
        push(&L2, i);
    }
    printList(L1);
    printList(L2); 
    printf("\n");
    Concatena(&L1, &L2);
    printList(L1);
    printList(L2);
    return 0;
}