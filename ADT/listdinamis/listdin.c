#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"
#include "../boolean/boolean.h"

void CreateListDin(ListDin *l, int capacity){
    BUFFER(*l) = (int*) malloc(capacity*sizeof(int));
    NEFF(*l) = 0;
    CAPACITY(*l) = capacity;
}

void dealocateList(ListDin *l){
    free(BUFFER(*l));
    CAPACITY(*l) = 0;
    NEFF(*l) = 0;
}

int listLength(ListDin l){
    return NEFF(l);
}

IdxType getFirstIdx(ListDin l){
    return 0;
}

IdxType getLastIdx(ListDin l){
    return NEFF(l)-1;
}

boolean isIdxValid(ListDin l, IdxType i){
    return (i<CAPACITY(l) && i>=0);
}

boolean isIdxEff(ListDin l, IdxType i){
    return (i>=0 && i<NEFF(l));
}

boolean isEmpty(ListDin l){
    return (NEFF(l)==0);
}

boolean isFull(ListDin l){
    return (NEFF(l)==CAPACITY(l));
}
void readList(ListDin *l){
    IdxType n,i;
    scanf("%d", &n);
    while (n<0 || n>CAPACITY(*l)){
        scanf("%d", &n);
    }
    NEFF(*l) = n;
    if (n!=0){
        for (i==0;i<(NEFF(*l));i++){
        scanf("%d", &ELMT(*l,i));
        }
    }
}

void printList(ListDin l){
    IdxType i;
    if (isEmpty(l)){
        printf("[]");
    } else{
        printf("[");
        for (i=0;i<listLength(l)-1;i++){
            printf("%d,",ELMT(l,i));
        }
        printf("%d",ELMT(l,i-1));
        printf("]");
    }
}

ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus){
    int i;
    ListDin lt;
    CreateListDin(&lt,CAPACITY(l1));
    NEFF(lt) = NEFF(l2);
    if (plus){
        for (i=0;i<NEFF(l1);i++){
            ELMT(lt,i) = ELMT(l1,i) + ELMT(l2,i);
        }
    } else{
        for (i=0;i<=NEFF(l1);i++){
            ELMT(lt,i) = ELMT(l1,i) - ELMT(l2,i);
        }   
    }
    return lt;
}

boolean isListEqual(ListDin l1, ListDin l2){
    IdxType i;
    boolean cek=true;
    if (NEFF(l1)!=NEFF(l2)){
        return false;
    } else{
        for (i=0; i< NEFF(l2); i++){
            if (ELMT(l1,i) != ELMT(l2,i)){
                cek = true;
            }
        }
        return cek;
    }
}
IdxType indexOf(ListDin l, ElType val){
    IdxType i=0;
    for(i=0;i<NEFF(l);i++){
        if (ELMT(l,i)==val){
            return i;
        }
    }
    return IDX_UNDEF;
}
void extremeValues(ListDin l, ElType *max, ElType *min){
    int i;
    *max = ELMT(l,0);
    *min = ELMT(l,0);
    for (i=1;i<NEFF(l);i++){
        if (ELMT(l,i)<*min){
            *min = ELMT(l,i);
        }
        if (ELMT(l,i)>*max){
            *max = ELMT(l,i);
        }
    }
}
void copyList(ListDin lIn, ListDin *lOut){
    IdxType i;
    dealocateList(lOut);
    CreateListDin(lOut,CAPACITY(lIn));
    NEFF(*lOut) = NEFF(lIn);
    for (i=0;i<NEFF(lIn);i++){
        ELMT(*lOut,i) = ELMT(lIn,i);
    }
}
ElType sumList(ListDin l){
    ElType temp = 0;
    IdxType i;
    if (isEmpty(l)){
        return 0;
    } else{
        for (i=0;i<NEFF(l);i++){
            temp += ELMT(l,i);
        }
        return temp;
    }
}

int countVal(ListDin l, ElType val){
    int temp = 0;
    IdxType i;
    for (i=0;i<NEFF(l);i++){
        if (ELMT(l,i)==val){
            temp++;
        }
    }
    return temp;
}

void sort(ListDin *l, boolean asc){
    ElType temp, id;
    IdxType i,j;
    ElType min = ELMT(*l,0);
    ElType max = ELMT(*l,0);
    if (asc){
        for (j=0; j<NEFF(*l);j++){
            for (i=0;i<NEFF(*l);i++){
                if (ELMT(*l,i)<min){
                    min = ELMT(*l,i);
                    id = i;
                }
            }
            temp = ELMT(*l,j);
            ELMT(*l,j) = min;
            ELMT(*l,id) = temp;
        }
    } else{
        for (j=0; i<NEFF(*l);i++){
            for (i=0;i<NEFF(*l);i++){
                if (ELMT(*l,i)>max){
                    max = ELMT(*l,i);
                    id = i;
                }
            }
            temp = ELMT(*l,j);
            ELMT(*l,j) = max;
            ELMT(*l,id) = temp;
        }
    }
}

void insertLast(ListDin *l, ElType val){
    ELMT(*l,NEFF(*l)) = val;
    NEFF(*l) = NEFF(*l) + 1;
}

void deleteLast(ListDin *l, ElType *val){
    *val = ELMT(*l, NEFF(*l)-1);
    NEFF(*l) = NEFF(*l) - 1;
}

void expandList(ListDin *l, int num){
    ListDin temp;
    CreateListDin(&temp, CAPACITY(*l));
    copyList(*l, &temp);
    int tempNeff = NEFF(*l);
    dealocateList(l);
    CreateListDin(l, CAPACITY(temp) + num);
    NEFF(*l) = tempNeff;

    int i;
    for (i=0; i<NEFF(temp); i++){
        ELMT(*l, i) = ELMT(temp,i);
    }
}

void shrinkList(ListDin *l, int num){
    ListDin temp;
    CreateListDin(&temp, CAPACITY(*l));
    copyList(*l, &temp);
    int NEFF_TEMP = NEFF(*l);

    CreateListDin(l, CAPACITY(temp)-num);

    NEFF(*l) = NEFF_TEMP;
    if(NEFF(*l)>CAPACITY(temp) - num ){
        NEFF(*l) = CAPACITY(temp) - num;
    }
    int i;
    for (i = 0; i<NEFF(*l);i++){
        ELMT(*l,i) = ELMT(temp,i);
    }
}

void compressList(ListDin *l)
{
    shrinkList(l, CAPACITY(*l)-NEFF(*l));
}