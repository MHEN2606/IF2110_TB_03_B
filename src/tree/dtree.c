#include <stdio.h>
#include "tree.h"

int main()
{
    Node N,child1,child2,childx,temp;
    N = *createNode(10);
    child1 = *newChild(&N,11);
    child2 = *newSibling(&child1,12);
    childx = *newChild(&child1,99);
    temp = N;
    printf("=================\n");
    printf("STRUKTUR TREE\n");
    printf("|-%d\n",tInfo(temp));
    temp = *firstChild(&temp);
    printf(" |- %d\n",tInfo(temp));
    printf("  |-%d\n",tInfo(childx));
    printf(" |- %d\n", tInfo(child2));
    printf("=================\n");
    return 0;
}