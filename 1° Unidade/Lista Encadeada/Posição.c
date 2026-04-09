// Escreva uma função que recebe uma lista encadeada e retorna a posição, a
// partir do início da lista (posição 1), da primeira ocorrência de um valor n,
// recebido por parâmetro. Se não houver, retornar o valor –1.

#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    int valor;
    struct Node *next;
}Node;

int Posicao(Node *Head, int n){
    int pos=-1;
    if(Head!=NULL){
        pos=1;
        while (Head != NULL && Head->valor!=n)
        {
            Head=Head->next;
            pos++;
        }
        if(!Head)
            pos=-1;
    }

    return pos;
    
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
    int num;
    // cria lista 1->2->3->4->5
    for (int i = 10; i >= 2; i--)
        push(&Head, i*3);
    num=Posicao(Head, 12);
    printf("%d", num);
    printList(Head);
    return 0;
}