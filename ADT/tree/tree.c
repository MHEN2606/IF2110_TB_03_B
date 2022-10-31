#include <stdio.h>
#include "tree.h"
#include <stdlib.h>
// #include "listdin.h"

/*Karna Tree bentuknya tidak bisa ditebak (sama seperti linked list), 
maka untuk membuat tree cukup menghubungkan node - node*/   

Node * createNode (treeinfo data)
/*Membuat dan mengembalikan suatu node baru dengan berisi firstChild dan nextSibling yang kosong*/
{
    Node * node_baru = malloc(sizeof(Node));
    if (node_baru){
        firstChild(node_baru) = NULL;
        nextSibling(node_baru) = NULL;
        tInfo(*node_baru) = data;
        // Depth(*node_baru) = 0;
    }
    return node_baru;
}

Node * newSibling (Node *x, treeinfo data)
/*Membuat suatu node yang merupakan sibling untuk node x*/
{
    /*Sambungkan semua sibling dari x dahulu dg menggunakan perulangan*/
    while (nextSibling(x) != NULL)
    {
        x = nextSibling(x); 
    }
    /*Hubungkan suatu node yang berisi data dengan sibling dari x*/
    nextSibling(x) = createNode(data);
    // Depth(*nextSibling(x)) = Depth(*x);
    return nextSibling(x);
}

Node * newChild (Node *x, treeinfo data)
/*Membuat suatu node yang merupakan anak dari node x*/
{
    /*Menggunakan percabangan untuk mengecek apabila node x
        - Memiliki child -> menjadi sibling dari child
        - Tidak punya child -> menjadi first child
    */
    if (firstChild(x)){
        return newSibling(firstChild(x),data);
    } else {
        // Depth(*firstChild(x)) = Depth(*x) + 1;
        firstChild(x) = createNode(data);
        return  firstChild(x);
    }
}

Node * find(Node *x,treeinfo data)
/*Mencari suatu node yang berisi data*/
/*Mengembalikan NULL apabila data tidak ditemukan*/
{
    /*While digunakan untuk mencari secara horizontal (sibling)*/
    while (x != NULL)
    {
        if (tInfo(*x)==data)
        {
            return x;
        }
        /*Mulai mencari secara vertikal (firstChild)*/
        if(firstChild(x)!=NULL)
        {
            /*Skema rekursif untuk tiap node*/
            Node *ret = find(firstChild(x),data);
            if (ret)
            {
                return ret;
            }
        }
        x = nextSibling(x);
    }
    return NULL;
}

// void * findChild(Node * x, treeinfo data)
// {
//     Node * a;
//     ListDin l;
//     CreateListDin(&l,10);
//     a = firstChild(x);
//     while (a != NULL)
//     {
//         insertLast(&l, Info(*a));
//         a = nextSibling(a);
//     }
// }