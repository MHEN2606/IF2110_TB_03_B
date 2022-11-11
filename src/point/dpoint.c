#include <stdio.h>
#include "point.h"

int main()
{
    POINT P;
    createPoint(&P,1,2);
    tulisPoint(P);
    return 0;
}