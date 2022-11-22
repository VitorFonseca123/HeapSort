#include <stdio.h>

typedef struct
{
    int A[101];
    int n;
} HEAP;

int pai(int i)
{
    return i / 2;
}
int filho_Left(int i)
{
    return 2 * i;
}
int filho_Right(int i)
{
    return 2 * i + 1;
}

void refazHeapMaximo(HEAP *h, int i)
{

    int L = filho_Left(i);
    int R = filho_Right(i);
    int maior = 0;
    if (L <= h->n && h->A[L] > h->A[i])
        maior = L;
    else
        maior = i;

    if (R <= h->n && h->A[R] > h->A[maior])
        maior = R;
    if (maior != i)
    {
        int aux = h->A[i];
        h->A[i] = h->A[maior];
        h->A[maior] = aux;
        refazHeapMaximo(h, maior);
    }
}
void constroiHeapMaximo(HEAP *h)
{

    for (int i = h->n / 2; i >= 1; i--)
    {

        refazHeapMaximo(h, i);
    }
}
void HeapSort(HEAP *h)
{

    constroiHeapMaximo(h);
    for (int i = (h->n); i >= 2; i--)
    {

        int aux = h->A[1];
        h->A[1] = h->A[i];
        h->A[i] = aux;

        refazHeapMaximo(h, 1);
    }
}
void exibir(HEAP h){

}
int main()
{
    int vetor[5] = {5, 2, 3, 1, 4};
    HEAP h;
    h.n = 5;
    for (int i = 1; i <= h.n; i++)
    {
        h.A[i] = vetor[i - 1];
        printf("%d ", h.A[i]);
    }
    HeapSort(&h);
    printf("\n");
    for (int i = 1; i <= h.n; i++)
    {
        printf("%d ", h.A[i]);
    }
    //exibir(h);
    
}