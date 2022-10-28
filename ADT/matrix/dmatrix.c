#include <stdio.h>
#include "matrix.h"
#include "../wordmachine/wordmachine.h"
#include "../charmachine/charmachine.h"
#include "../point/point.h"

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
    moveEast(&p,&m);
    tulisPoint(p);
    displayMatrix(m);
    moveWest(&p,&m);
    tulisPoint(p);
    displayMatrix(m);
    return 0;
}