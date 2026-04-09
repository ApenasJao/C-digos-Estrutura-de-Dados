// Uma companhia aérea quer armazenar as seguintes informações de cada
// um de seus clientes: código do cliente (um número inteiro), preço da
// passagem, idade, tipo da passagem (A, B ou C). Escreva uma função que
// receba um vetor de clientes dessa companhia, bem como o seu tamanho. A
// função deve criar um novo vetor contendo apenas as informações dos
// clientes com menos de 18 anos e cujo preço da passagem seja maior que
// 1000 reais. Não pode haver desperdício de memória, ou seja, o novo vetor
// deve ser alocado dinamicamente.

// O tipo Cliente é dado por:
#include <stdlib.h>
#include <stdio.h>

typedef struct{

    int codigo;
    float preco;
    int idade;
    char tipo;

}Cliente;

void Cliente_18(Cliente *vetor, Cliente **vetor_novo, int tam, int *tam_novo){
    *vetor_novo = NULL;

    for (int i = 0; i < tam; i++)
    {
        if((vetor[i].idade) < 18 && (vetor[i].preco) > 1000){

            (*vetor_novo) = realloc(*vetor_novo, (*tam_novo + 1) * (sizeof(Cliente)));
    
            if((vetor_novo) == NULL){
                printf("Erro de alocacao");
                exit(1);
            }
            (*vetor_novo)[*tam_novo] = vetor[i];
            (*tam_novo)++;

        }
    }
}

void insere_vetor(Cliente c, Cliente **vetor, int *tam){
    *vetor = realloc(*vetor, (*tam + 1) * sizeof(Cliente));
    
    if((*vetor) == NULL){
        printf("Erro de alocacao");
        exit(1);
    }
    (*vetor)[*tam] = c;
    (*tam)++;

}

void imprime(Cliente *vetor, int tam){

    printf("\nClientes cadastrados:\n");
    for (int i = 0; i < tam; i++)
        printf("Codigo: %d , Preco: %.2f , Idade: %d, Tipo: %c\n", vetor[i].codigo, vetor[i].preco, vetor[i].idade, vetor[i].tipo);
}

int main(){
    
    int resp=1;

    Cliente *vetor = NULL;
    Cliente *vetor_novo;
    int tam = 0;
    int tam_novo = 0;

    while(resp!= 0){
        Cliente c;

        printf("\nInsira o seu codigo:");
        scanf("%d", &c.codigo);
        printf("\nInsira o seu preco:");
        scanf("%f", &c.preco);
        printf("\nInsira sua idade:");
        scanf("%d", &c.idade);
        printf("\nInsira seu tipo:");
        scanf(" %c", &c.tipo);
        
        insere_vetor(c, &vetor, &tam);

        printf("\nDeseja inserir um novo cliente? (0-Nao 1-Sim) ");
        scanf("%d", &resp);

    }

    imprime(vetor, tam);
    Cliente_18(vetor, &vetor_novo, tam, &tam_novo);

    imprime(vetor_novo, tam_novo);
    return 0;

}