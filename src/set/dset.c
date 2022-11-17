#include <stdio.h>
#include "set.h"

int main()
{
    Set S,S2;
    creteSet(&S);
    insert(&S,1);
    insert(&S,2);
    deleteElSet(&S,1);
    insert(&S2,2);
    insert(&S2,3);
    if (isSubset(S,S2))
    {
        printf("HUOOO");
    }
    LENST(S) = 0;
    displaySet(S);
}