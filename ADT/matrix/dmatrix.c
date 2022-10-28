#include <stdio.h>
#include "matrix.h"
#include "wordmachine.h"
#include "charmachine.h"
#include "point.h"

int main() {
    Matrix m;
    POINT p;
    readMatrix(&m,&p);
    tulisPoint(p);
    displayMatrix(m);
    moveNorth(&p,&m);
    tulisPoint(p);
    displayMatrix(m);
    moveSouth(&p,&m);
    tulisPoint(p);
    displayMatrix(m);
    moveSouth(&p,&m);
    tulisPoint(p);
    displayMatrix(m);
    moveNorth(&p,&m);
    tulisPoint(p);
    displayMatrix(m);
    return 0;
}