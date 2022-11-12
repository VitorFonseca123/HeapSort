#include <stdio.h>

typedef struct 
{
    int A[5];
    int n;
    int tamanhoDoHeap;
}HEAP;

int pai(int i){
    return i/2;
}
int filho_Left(int i){
    return 2*i;
}
int filho_Right(int i){
    return 2*i+1;
}

void refazHeapMaximo(int A[],int i){
    int L =filho_Left(i);
    int R = filho_Right(i);
    int maior=0;
    if(L<=tamanhoDoHeap[A] && A[R]>A[i]) maior=L;
    else maior=i;

    if(R<=tamanhoDoHeap[A] && A[R]>A[maior]) maior=R;
    if(maior != i){
        int aux=A[i];
        A[i]= A[maior];
        A[maior]=aux;
        refazHeapMaximo(A, maior);
    }
}
void HeapSort(HEAP* h)
{
    constroiHeapMaximo(h);
    for(int i)
}
int main(){
    int vetor[5] = {5, 2, 3, 1, 4};

}
