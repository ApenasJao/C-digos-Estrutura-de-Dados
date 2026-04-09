#include <stdio.h>
#include <stdlib.h>

void swap(int *v, int i, int j){
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;

}

void QuickSort(int *v, int L, int R){
    if(L>=R)
        return;
    int i = L;
    int j = R-1;
    int m = (L + R) /2;
    int pivo = v[m];
    swap(v, m, R);

    while(i<=j){

        while(i<=R && v[i] <= pivo)
            i++;
        while(j>=L && v[j] >= pivo)
            j--;
        if(i<=j){
            swap(v, i , j);
            i++;
            j--;
        }
    }
    swap(v, R, j + 1);
    QuickSort(v, L, j);
    QuickSort(v, j + 2, R);
}



int main(){
    int vetor[10] = {7,9,3,2,1,7,8,5,6,0};
    QuickSort(vetor, 0, 9);
    QuickSort(vetor, 0, 9);
    for(int i=0;i<10;i++)
        printf("%d -> ", vetor[i]);
    return 0;
}