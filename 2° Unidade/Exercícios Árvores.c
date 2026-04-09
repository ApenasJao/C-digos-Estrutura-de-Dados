#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int key;
    int height;
    struct Node *left;
    struct Node *right;
}Node;

//=======================================CREATE=================================
Node *create(int key){

    Node *novo = (Node*) malloc(sizeof(Node));
    novo->key = key;
    novo->left = NULL;
    novo->right = NULL;
    novo->height = 1;
    return novo;
}

//=====================================HEIGHT====================================
int height(Node *root){
    return root? root->height:0;
}

//=======================================MAX=================================
int max(int a, int b) {
    return (a > b) ? a : b;
}

//=======================================Fator de BAlanceamento =================================

int fatorbalanceamento(Node* root){
    return root? height(root->left) - height(root->right):0;
}

//=======================================ROTAÇÃO ESQUERDA=================================

Node *rotate_left(Node *root){
    Node *son = root->right;
    root->right = son->left;
    son->left = root;

    root->height = max(height(root->left), height(root->right)) + 1;
    son->height = max(height(son->left), height(son->right)) + 1;
    

    return son;
}

//=======================================ROTAÇÃO ESQUERDA=================================
Node *rotate_right(Node* root){
    Node *son = root->left;
    root->left = son->right;
    son->right = root;

    root->height = max(height(root->left), height(root->right)) + 1;
    son->height = max(height(son->left), height(son->right)) + 1;
    
    return son;
}

//=======================================LIMPAR ARVORE=================================
void clear(Node*root){
    if(!root)
        return;
    clear(root->left);
    clear(root->right);
    free(root);
}

//=======================================IMPRIMIR EM ORDEM=================================

void imprime_emordem(Node*root){
    if(!root)
        return;
    imprime_emordem(root->left);
    printf("%d ", root->key);
    imprime_emordem(root->right); 
}

Node *insere(Node *root, int key){
    if(!root)
        return create(key);

    if(key < root->key){
        root->left = insere(root->left, key);
    }
    else if (key > root->key){
        root->right = insere(root->right, key);
    }
    else{
        return root;
    }

    root->height = max(height(root->left), height(root->right)) + 1; 
    int fb = fatorbalanceamento(root);

    if(fb > 1 && fatorbalanceamento(root->left) > 0) 
        return rotate_right(root);

    if(fb < -1 && fatorbalanceamento(root->right) < 0) 
        return rotate_left(root);

    if(fb > 1 && fatorbalanceamento(root->left) < 0){
        root->left = rotate_left(root->left);
        return rotate_right(root);
    }

    if(fb < -1 && fatorbalanceamento(root->right) > 0){
        root->right = rotate_right(root->right);
        return rotate_left(root);
    }

    return root;
}

Node *NoMinimo(Node *root) {
    Node *aux = root;
    while (aux->left != NULL)
        aux = aux->left;
    return aux;
}


///////////////////////////////////////////////FUNÇÃO DE REMOVER/////////////////////////////////////////////
Node *removeAVL(Node *root, int key) {
    // 1. Remover como em uma BST normal
    if (!root)
        return root;

    if (key < root->key)
        root->left = removeAVL(root->left, key);
    else if (key > root->key)
        root->right = removeAVL(root->right, key);
    else {
        // Nó encontrado
        if ((root->left == NULL) || (root->right == NULL)) {
            Node *temp = root->left ? root->left : root->right;

            // Sem filhos (folha)
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                // Um único filho
                *root = *temp;
            }
            free(temp);
        } else {
            // Dois filhos → substitui pelo sucessor (menor da direita)
            Node *temp = NoMinimo(root->right);
            root->key = temp->key;
            root->right = removeAVL(root->right, temp->key);
        }
    }

    // Se a árvore ficou vazia
    if (!root)
        return root;

    // 2. Atualiza a altura
    root->height = 1 + max(height(root->left), height(root->right));

    // 3. Calcula o balanceamento
    int balance = fatorbalanceamento(root);

    // 4. Corrige desbalanceamentos

    // Esquerda - Esquerda
    if (balance > 1 && fatorbalanceamento(root->left) >= 0)
        return rotate_right(root);

    // Esquerda - Direita
    if (balance > 1 && fatorbalanceamento(root->left) < 0) {
        root->left = rotate_left(root->left);
        return rotate_right(root);
    }

    // Direita - Direita
    if (balance < -1 && fatorbalanceamento(root->right) <= 0)
        return rotate_left(root);

    // Direita - Esquerda
    if (balance < -1 && fatorbalanceamento(root->right) > 0) {
        root->right = rotate_right(root->right);
        return rotate_left(root);
    }

    return root;
}


//=======================================SOMA DE TODOS OS NÓS=================================
int CalculaSoma(Node* root){
    return root ? root->key + CalculaSoma(root->left) + CalculaSoma(root->right) : 0;  
}

//=======================================SOMA DAS FOLHAS=================================
int Calculafolha(Node *root){
    if(root == NULL)
        return 0;

    if(root->left == NULL && root->right == NULL) 
        return root->key;

    return Calculafolha(root->left) + Calculafolha(root->right);
}

// ////////////////////Escreva uma função que recebe uma árvore binária e retorna a
// quantidade de nós da árvore que possuem apenas 1 filho. Essa função
// deve ser recursiva.

int CalculaUmFilho(Node *root){
    if(!root)
        return 0;
    if((!root->left && root->right) || (root->left && !root->right))
        return 1;
    return CalculaUmFilho(root->left) + CalculaUmFilho(root->right);
}

// Escreva uma função que recebe uma árvore, verifica se a árvore tem mais
// nós na sub-árvore esquerda ou na sub-árvore direita.

int SomaNo(Node *root){
    return root? 1 + SomaNo(root->left) + SomaNo(root->right):0;
}

int Verificasub(Node *root){
    if(!root)
        return 0;
    int sub_esq = SomaNo(root->left);
    int sub_dir = SomaNo(root->right);
    if(sub_esq > sub_dir)
        return -1;
    if(sub_esq < sub_dir)
        return 1;

    return 0;
}

// Escreva uma função que recebe uma árvore binária de busca e verifica
// se ela é estritamente binária. Uma árvore binária de busca é estritamente
// binária se todos os nós da árvore (exceto as folhas) tem 2 filhos

int VerificaB(Node*root){
    if(!root)
        return 1;

    if((root->left && !root->right) || (!root->left && root->right))
        return 0;

    return VerificaB(root->left) && VerificaB(root->right);
    
}

// Escreva uma função que recebe uma árvore binária e calcula e retorna a
// quantidade de nós internos da árvore.

int ContaNoInterno(Node *root){

    if (!root)
        return 0;
    
    if((!root->left) && (!root->right))
        return 0;
        
    return 1 + ContaNoInterno(root->left) + ContaNoInterno(root->right);
}

// Escreva uma função que conta o número de descendentes da raiz de uma
// árvore. Se a árvore estiver vazia, a função deve retornar -1.

int ContaDescendentes(Node *root){
    if(!root)
        return -1;
    
    int total = 0;

    if(root->left)
        total += 1 + ContaDescendentes(root->left);
    if(root->right)
        total += 1 + ContaDescendentes(root->right);
    
    return total;
}

// Escreva uma função que recebe uma árvore binária de busca e devolve
// o valor da chave do elemento que possui a menor chave.

int MenorChave(Node *root){
    if(!root)
        return 0;

    Node *aux = root;
    while(aux->left)
        aux = aux->left;

    return aux->key;
}

// Escreva uma função que recebe uma árvore binária de busca e o valor de
// um nó e retorna a quantidade de nós descendentes cujas chaves são
// menores que a desse nó. Se o nó não estiver na árvore retornar 0.

int contamenores(Node *root , int no){
    if(!root)
        return 0;
    
    int cont = 0;
    if(no > root->key){
        cont = 1 + contamenores(root->left, no) + contamenores(root->right, no);
    }
   else{
        cont = contamenores(root->left, no);
    }
    return cont;
}

int MenoresNo(Node *root, int no){
    if(!root)
        return 0;

    Node *aux = root;
    while(aux && aux->key != no){
        if(no < aux->key)
            aux = aux->left;
        else{
            aux = aux->right;
        }
    }

    if(!aux)
        return 0;
    
    return contamenores(root->left, no) + contamenores(root->right, no);

}

// Escreva uma função que recebe uma árvore binária de busca e retira o
// maior elemento da árvore e o devolve.

Node *Removeinsere(Node *root){
    if(!root)
        return NULL;
    
    Node* aux = root;
    while(aux->right){
        aux = aux->right;
    }

    int maior = aux->key;
    root = removeAVL(root, maior);
    root = insere(root, maior);
    return root;
}





// Escreva uma função que recebe duas árvores binárias e verifica se elas
// são similares. Duas árvores binárias são similares se elas são vazias ou
// se ambas armazenam o mesmo valor em seu nó raiz, suas sub-árvores
// da esquerda são similares e suas sub-árvores da direita também são
// similares.

int Similares(Node *root1, Node *root2){

    if(!root1 && !root2)
        return 1;
    if((root1 && !root2) || (!root1 && root2))
        return 0;
    if(root1->key != root2->key)
        return 0;
    
    return Similares(root1->left, root2->left) && Similares(root1->right, root2->right);

}
//=======================================MAIN=================================
int main(){
    Node *root = NULL;

   // Inserindo valores
    root = insere(root, 4);
    root = insere(root, 6);
    root = insere(root, 9);
    root = insere(root, 8);
    root = insere(root, 2);
    root = insere(root, 3);
    root = insere(root, 7);
    root = insere(root, 5);
    root = insere(root, 1);
    root = insere(root, 14);
    root = insere(root, 13);



    

    printf("Árvore em ordem: ");
    imprime_emordem(root);

    printf("\nSoma das folhas: %d", Calculafolha(root));
    printf("\nSoma de todos os nos: %d", CalculaSoma(root));
    printf("\nSoma de todos os nos com apenas um filho: %d", CalculaUmFilho(root));


    printf("\n%d", SomaNo(root));
    if(Verificasub(root) == -1)
        printf("\nA maior sub arvore e a esquerda");
    else if(Verificasub(root) == 1)
        printf("\nA maior sub arvore e a direita");
    else{
        printf("\nVazia ou são iguais");
    }

    if(VerificaB(root) == 1)
        printf("\nA arvore é estritamente binaria");
    else{
        printf("\nA arvore nao e estritamente binaria");
    }

    printf("\n%d", ContaNoInterno(root));

    printf("\nNumero de descendentes: %d", ContaDescendentes(root));
    printf("\nA menor chave da arvore: %d", MenorChave(root));

    printf("\nMenores que o no 6: %d", MenoresNo(root, 6));
    clear(root);

    return 0;
}