#include <stdio.h>
#include "matrix.h"
#include "wordmachine.h"
#include "charmachine.h"
#include "point.h"

int main() {
    Matrix m;
    POINT p;
    readMatrix(&m,&p);
    displayMatrix(m);
}