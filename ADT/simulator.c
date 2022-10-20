#include <stdio.h>
#include "simulator.h"
#include "point.h"
#include "liststatik.h"

void createUser(SIMULATOR *S, POINT origin, char name, ListStatik inv){
/* Membuat User S dengan posisi POINT origin dan inventory FOODLIST inv*/
    USERNAME(*S) = name;
    POSISI(*S) = origin;
    INV(*S) = inv;
}