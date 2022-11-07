#include <stdio.h>
#include "stack.h"

int main()
{
    STACK S;
    createEmptyStack(&S);
    printf("=====================================\n");
    printf("Buat stack kosong\n");
    printf("Cek apakah list kosong?\n");
    if (isEmpty(S))
    {
        printf("List Kosong\n");
    }
    else
    {
        printf("List terisi\n");
    }
    printf("Push [1]\n");
    printf("Cek apakah list kosong?\n");
    Push(&S,1);
    if (isEmpty(S))
    {
        printf("List Kosong\n");
    }
    else
    {
        printf("List terisi\n");
    }
    printf("Cek apakah list penuh?\n");
    if (isFull(S))
    {
        printf("List Penuh\n");
    }
    else
    {
        printf("List tidak penuh\n");
    }
    int x;
    printf("Lakukan Pop\n");
    printf("Elemen yang di pop : ");
    Pop(&S,&x);
    printf("%d\n",x);
    printf("=====================================");
}