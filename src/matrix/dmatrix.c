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
    moveNorth(&p,&m); //move north
    tulisPoint(p);
    displayMatrix(m);
    moveSouth(&p,&m); //move south
    tulisPoint(p);
    displayMatrix(m);
    moveEast(&p,&m); //move east
    tulisPoint(p);
    displayMatrix(m);
    moveWest(&p,&m); //move west
    tulisPoint(p);
    displayMatrix(m);
    return 0;
}