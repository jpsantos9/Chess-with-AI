#include <iostream>
#include <sstream>
#include "Pieces.h"

using namespace std;

pawn::pawn() {
    //setA=setB=0;
}

//check if valid move
bool pawn::rightMoves(int a, int b, int x, int y){
    //if pawn is white
    if (color=='W'){
        if (y=b-1){
            return true;
        }
        else {
            return false;
        }
    }
    //if black
    else if (color=='B'){
        if (y=b+1){
            return true;
        }
        else {
            return false;
        }
    }
}
