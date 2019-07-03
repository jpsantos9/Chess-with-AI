#include <iostream>
#include <fstream>
#include "Pieces.h"

using namespace std;

struct player {
    //to indicate the color of the player
    char color;
    //set the pieces to the player
    int pawnNum[16];
};

//logo
void printLogo () {
    cout << " __________   ___      ___   __________   __________   __________   ___ \n";
    cout << "|          | |   |    |   | |          | |          | |          | |   |\n";
    cout << "|     _____| |   |    |   | |    ______| |     _____| |     _____| |   |\n";
    cout << "|    |       |   |____|   | |   |______  |    |_____  |    |_____  |   |\n";
    cout << "|    |       |            | |          | |          | |          | |   |\n";
    cout << "|    |       |    ____    | |    ______| |_____     | |_____     | |___|\n";
    cout << "|    |_____  |   |    |   | |   |______   _____|    |  _____|    |  ___ \n";
    cout << "|          | |   |    |   | |          | |          | |          | |   |\n";
    cout << "|__________| |___|    |___| |__________| |__________| |__________| |___|\n";
}

//start menu
void printMenu(){
    cout << "\nWelcome to Chess!!!\n";
    cout << "   Press: \n";
    cout << "   [1] Start Game\n";
    cout << "   [2] User Manual\n";
    cout << "   [3] Exit\n   ";
    return;
}

//user manual
void userManual(){
    cout<<"User Manual"<<endl;
}

//get board from a file
void getBoard (char board[25][8]){
    int x=0, y=0;
    //read from the file
    ifstream theFile ("board.txt", ios::in);
    //get the board and place in char arrey w/ proper coordinats
    while (theFile>>board[x][y]){
        x++;
        if (x==25){
            y++;
            x=0;
        }
    }
}

//print board function
void printBoard (char board[25][8]){
    //print board
    cout<<" _A _B _C _D _E _F _G _H"<<endl;
    for (int y=0; y<8; y++){
        for (int x=0; x<25; x++){
            cout<<board[x][y];
        }
        cout<<endl;
    }
    cout<<endl;
}

//place pieces to board
void placePieces (pawn wew[32], char board [25][8], int a, int b, int x, int y, int z){
    //clear previous
    board[a][b]='_';
    board[a-1][b]='_';
    //replace new position
    wew[z].positionX=x;
    wew[z].positionY=y;
    //place sym in board
    board [wew[z].positionX][wew[z].positionY] = wew[z].sym;
    //place color in board
    board [wew[z].positionX-1][wew[z].positionY] = wew[z].color;
}

//ask for the piece that will be moved
//return x and y
void whatPiece (int &x, int &y, char board[25][8]){
    char letx;
    cout<<"What piece do you wish to move? "<<endl<<"A-H: ";
    cin>>letx;
    cout<<"1-8: ";
    cin>>y;
    y=y-1;
    //convert letter to x
    if (letx == 'A'){
        x=2;
    }
    else if (letx =='B'){
        x=5;
    }
    else if (letx =='C'){
        x=8;
    }
    else if (letx =='D'){
        x=11;
    }
    else if (letx =='E'){
        x=14;
    }
    else if (letx =='F'){
        x=17;
    }
    else if (letx =='G'){
        x=20;
    }
    else if (letx =='H'){
        x=23;
    }

}

//check if there is a piece
bool checkLoad (int x, int y, char board[25][8]){
    //if no piece return false
    if (board[x][y]=='_'){
        cout<<"empty"<<endl;
        return false;
    }
    //if with piece return true
    else {
        cout<<"full"<<endl;
        return true;
    }
}

//check the color
bool checkcolor (int x, int y, char board[25][8], player person[2], int z){
    if (board[x-1][y] == person[z].color){
        return true;
    }
    else {
        cout<<"WRONG COLOR!"<<endl;
        return false;
    }
}

//find the piece number
bool checkPieceNum (int a, int b, pawn Num){
    if (Num.positionX==a && Num.positionY==b){
        return true;
    }
    else {
        return false;
    }
}

//ask for next move
void askMove (int &x, int &y, char board[25][8]){
    char letx, temp;
    cout<<"what is your move? "<<endl;
    cout<<"A-H: ";
    cin>>letx;
    cout<<"1-8: ";
    cin>>y;
    y=y-1;
    //convert letter to x
    if (letx == 'A' || letx == 'a'){
        x=2;
    }
    else if (letx =='B' || letx == 'b'){
        x=5;
    }
    else if (letx =='C' || letx == 'c'){
        x=8;
    }
    else if (letx =='D' || letx == 'd'){
        x=11;
    }
    else if (letx =='E' || letx == 'e'){
        x=14;
    }
    else if (letx =='F' || letx == 'f'){
        x=17;
    }
    else if (letx =='G' || letx == 'g'){
        x=20;
    }
    else if (letx =='H' || letx == 'h'){
        x=23;
    }

}

//pawn possible moves
bool pMoves (int x, int y, pawn wew){
    if ((wew.positionY == y-1 && wew.positionX == x) || (wew.positionY == y-1 && wew.positionX == x+3) || (wew.positionY == y-1 && wew.positionX == x-3) || (wew.positionY == y-2 && wew.positionX == x)){
        return true;
    }
    else if ((wew.positionY == y+1 && wew.positionX == x) || (wew.positionY == y+1 && wew.positionX == x+3) || (wew.positionY == y+1 && wew.positionX == x-3) || (wew.positionY == y+2 && wew.positionX == x)){
        return true;
    }
    else {
        cout<<"INVALID MOVE!"<<endl;
        return false;
    }
}

//rook possible moves
bool rMoves (int x, int y, pawn wew){
    if (wew.positionX==x){
        return true;
    }
    if (wew.positionY==y){
        return true;
    }
    else {
        cout<<"INVALID MOVE!"<<endl;
        return false;
    }
}

//knight possible moves
bool nMoves (int x, int y, pawn wew){
    if ((wew.positionX==x+3 || wew.positionX==x-3) && (wew.positionY==y+2 || wew.positionY==y-2)){
        return true;
    }
    else if ((wew.positionX==x+6 || wew.positionX==x-6) && (wew.positionY==y+1 || wew.positionY==y-1)){
        return true;
    }
    else {
        cout<<"INVALID MOVE!"<<endl;
        return false;
    }
}

//bishop possible moves
bool bMoves (int x, int y, pawn wew){
    int a;
    //if y is higher
    if (y>wew.positionY){
        a=(y-wew.positionY)*3;
        if (wew.positionX==x+a || wew.positionX==x-a){
            return true;
        }
        else {
            cout<<"INVALID MOVE!"<<endl;
            return false;
        }
    }
    else {
        a=(wew.positionY-y)*3;
        if (wew.positionX==x+a || wew.positionX==x-a){
            return true;
        }
        else {
            cout<<"INVALID MOVE!"<<endl;
            return false;
        }
    }
}

//queen possible moves
bool qMoves (int x, int y, pawn wew){
    //for straigth moves
    if (wew.positionX==x){
        return true;
    }
    else if (wew.positionY==y){
        return true;
    }
    //for diagonal moves
    int a;
    //if y is higher
    if (y>wew.positionY){
        a=(y-wew.positionY)*3;
        if (wew.positionX==x+a || wew.positionX==x-a){
            return true;
        }
        else {
            cout<<"INVALID MOVE!"<<endl;
            return false;
        }
    }
    else if (y<wew.positionY) {
        a=(wew.positionY-y)*3;
        if (wew.positionX==x+a || wew.positionX==x-a){
            return true;
        }
        else {
            cout<<"INVALID MOVE!"<<endl;
            return false;
        }
    }
}

//king possible moves
bool kMoves (int x, int y, pawn wew){
    if ((wew.positionX==x-3||wew.positionX==x+3) && (wew.positionY==y||wew.positionY==y+1||wew.positionY==y-1)){
        return true;
    }
    else if ((wew.positionY==y+1||wew.positionY==y-1) && (wew.positionX==x-3||wew.positionX==x+3||wew.positionX==x)){
        return true;
    }
    else {
        cout<<"INVALID MOVE!"<<endl;
        return false;
    }
}

//remove enemy piece and clear position
void Eat (int x, int y, pawn wew[32], char board[25][8], int z){
    //remove prey from board
    wew[z].positionX=100;
    wew[z].positionY=100;
    //clear position in board
    board[x][y]='_';
}

int main () {
    int a, b ,x ,y;
    //initialize board
    char board[25][8];
    //get board using function
    getBoard(board);
    //print board
    printBoard(board);
//-----------------------------------------//
    //initialize all pieces in board
    pawn chessP[32];
    //initial positions of white PAWN (0-7)
    int test=2;
    //x is the piece num
    //initialize PAWNS
    for (x=0; x<8; x++){
        //assign as white
        chessP[x].color='W';
        chessP[x].sym='P';
        //assign initial position
        chessP[x].positionX=test;
        test= test+3;
        chessP[x].positionY=6;
        //initial placement in board
        board[chessP[x].positionX][chessP[x].positionY]=chessP[x].sym;
        board[chessP[x].positionX-1][chessP[x].positionY]=chessP[x].color;
    }
    //initialize ROOK (8-9)
    test=2;
    for (x=8; x<10; x++){
        //assign color and sym
        chessP[x].color='W';
        chessP[x].sym='R';
        //assign initial position
        chessP[x].positionX=test;
        test=test+21;
        chessP[x].positionY=7;
        //initial placement in board
        board[chessP[x].positionX][chessP[x].positionY]=chessP[x].sym;
        board[chessP[x].positionX-1][chessP[x].positionY]=chessP[x].color;
    }
    //initialize KNIGHT (10-11)
    test=5;
    for (x=10; x<12; x++){
        //assign color and sym
        chessP[x].color='W';
        chessP[x].sym='N';
        //assign initial position
        chessP[x].positionX=test;
        test=test+15;
        chessP[x].positionY=7;
        //initial placement in board
        board[chessP[x].positionX][chessP[x].positionY]=chessP[x].sym;
        board[chessP[x].positionX-1][chessP[x].positionY]=chessP[x].color;
    }
    //initialize BISHOP (12-13)
    test=8;
    for (x=12; x<14; x++){
        //assign color and sym
        chessP[x].color='W';
        chessP[x].sym='B';
        //assign initial position
        chessP[x].positionX=test;
        test=test+9;
        chessP[x].positionY=7;
        //initial placement in board
        board[chessP[x].positionX][chessP[x].positionY]=chessP[x].sym;
        board[chessP[x].positionX-1][chessP[x].positionY]=chessP[x].color;
    }
    //initialize Queen
    for (x=14; x<15; x++){
        //assign color and sym
        chessP[x].color='W';
        chessP[x].sym='Q';
        //assign initial position
        chessP[x].positionX=14;
        chessP[x].positionY=7;
        //initial placement in board
        board[chessP[x].positionX][chessP[x].positionY]=chessP[x].sym;
        board[chessP[x].positionX-1][chessP[x].positionY]=chessP[x].color;
    }
    //initialize KING
    for (x=15; x<16; x++){
        //assign color and sym
        chessP[x].color='W';
        chessP[x].sym='K';
        //assign initial position
        chessP[x].positionX=11;
        chessP[x].positionY=7;
        //initial placement in board
        board[chessP[x].positionX][chessP[x].positionY]=chessP[x].sym;
        board[chessP[x].positionX-1][chessP[x].positionY]=chessP[x].color;
    }

    //initialize BLACK PAWNS (16-23)
    test=2;
    for (x=16; x<24; x++){
        //assign as white
        chessP[x].color='B';
        chessP[x].sym='P';
        //assign initial position
        chessP[x].positionX=test;
        test= test+3;
        chessP[x].positionY=1;
        //initial placement in board
        board[chessP[x].positionX][chessP[x].positionY]=chessP[x].sym;
        board[chessP[x].positionX-1][chessP[x].positionY]=chessP[x].color;
    }
    //initialize ROOKS (24-25)
    test=2;
    for (x=24; x<26; x++){
        //assign color and sym
        chessP[x].color='B';
        chessP[x].sym='R';
        //assign initial position
        chessP[x].positionX=test;
        test=test+21;
        chessP[x].positionY=0;
        //initial placement in board
        board[chessP[x].positionX][chessP[x].positionY]=chessP[x].sym;
        board[chessP[x].positionX-1][chessP[x].positionY]=chessP[x].color;
    }
    //initialize KNIGHTS (26-27)
    test=5;
    for (x=26; x<28; x++){
        //assign color and sym
        chessP[x].color='B';
        chessP[x].sym='N';
        //assign initial position
        chessP[x].positionX=test;
        test=test+15;
        chessP[x].positionY=0;
        //initial placement in board
        board[chessP[x].positionX][chessP[x].positionY]=chessP[x].sym;
        board[chessP[x].positionX-1][chessP[x].positionY]=chessP[x].color;
    }
    //initialize BISHOP (28-29)
    test=8;
    for (x=28; x<30; x++){
        //assign color and sym
        chessP[x].color='B';
        chessP[x].sym='B';
        //assign initial position
        chessP[x].positionX=test;
        test=test+9;
        chessP[x].positionY=0;
        //initial placement in board
        board[chessP[x].positionX][chessP[x].positionY]=chessP[x].sym;
        board[chessP[x].positionX-1][chessP[x].positionY]=chessP[x].color;
    }
    //initialize QUEEN
    for (x=30; x<31; x++){
        //assign color and sym
        chessP[x].color='B';
        chessP[x].sym='Q';
        //assign initial position
        chessP[x].positionX=11;
        chessP[x].positionY=0;
        //initial placement in board
        board[chessP[x].positionX][chessP[x].positionY]=chessP[x].sym;
        board[chessP[x].positionX-1][chessP[x].positionY]=chessP[x].color;
    }
    //initialize KING
    for (x=31; x<32; x++){
        //assign color and sym
        chessP[x].color='B';
        chessP[x].sym='K';
        //assign initial position
        chessP[x].positionX=14;
        chessP[x].positionY=0;
        //initial placement in board
        board[chessP[x].positionX][chessP[x].positionY]=chessP[x].sym;
        board[chessP[x].positionX-1][chessP[x].positionY]=chessP[x].color;
    }

    //idon't know what is this
    for (x=16;x<32;x++){
        cout<<"("<<chessP[x].positionX<<","<<chessP[x].positionY<<") ";
    }
    cout<<endl;

    printBoard(board);

//---------------------------------------//
    //initialize pieces to players
    player person[2];
    person[0].color='W';
    person[1].color='B';
//--------------------------------------//
    //menu
    int choice;
    printLogo();
    do {
        printMenu();
        cin>>choice;
        //if choice is 1 start game
        if (choice == 1){
            //start game
            printBoard(board);
            //"who" is to indicate the player number
            int n=0, who=0;
            //if the king is eaten GAME OVER
            while (chessP[15].positionX!=100 && chessP[31].positionX!=100){
                //Print the Who will move
                if (who==0){
                    cout<<"White Player"<<endl;
                }
                else if (who==1) {
                    cout<<"Black Player"<<endl;
                }
                //get the piece
                do {
                    whatPiece(a, b, board);
                } while (!checkcolor(a, b, board, person, who));
                //get piece num (test) *problem
                test=0;
                while (!checkPieceNum(a, b, chessP[test])){
                    test++;
                }
                cout<<test;
                //while next move is not empty
                do {
                //move Restrictions
                    //If Piece is Pawn
                    if (chessP[test].sym == 'P'){
                        do {
                            //ask for the next move
                            askMove(x, y, board);
                            //if forward move, there should be no piece
                            if (x == chessP[test].positionX){
                                //check if there is a piece
                                if (checkLoad(x, y, board)){
                                    cout<<"INVALID MOVE"<<endl;
                                }
                            }
                            //if diagonal move, there shoudl be enemy
                            else {
                                //check if there is a piece
                                if (checkLoad(x, y, board)){
                                    //if same color
                                    if(checkcolor(x, y, board, person, who)){
                                        cout<<"SAME COLOR"<<endl;
                                    }
                                    //if other color
                                    else {
                                        //check if valid move before eating
                                        if (pMoves(x, y, chessP[test])){
                                            //eat function
                                            //find the prey number
                                            int prey=0;
                                            //find number of enemy piece
                                            while (!checkPieceNum(x, y, chessP[prey])){
                                                prey++;
                                            }
                                            cout<<"prey: "<<prey<<endl;
                                            //eat function
                                            Eat(x, y, chessP, board, prey);
                                        }
                                    }
                                }
                                //if diagonal has no piece
                                else {
                                    cout<<"INVALID MOVE!"<<endl;
                                    //so that the move will be invalid
                                    y = chessP[test].positionY+2;
                                }
                            }
                        //else just place
                        } while (!pMoves(x, y, chessP[test]));
                    }
                    //if Rook
                    else if (chessP[test].sym =='R') {
                        do {
                            askMove(x, y, board);
                            //check if next move have a piece
                            //if have a piece then ...
                            if (checkLoad(x, y, board)){
                                //if white
                                if(checkcolor(x, y, board, person, who)){
                                    cout<<"SAME COLOR"<<endl;
                                }
                                //if black
                                else {
                                    //eat function
                                    //find the prey number
                                    //get piece num (test) *problem
                                    int prey=0;
                                    while (!checkPieceNum(x, y, chessP[prey])){
                                        prey++;
                                    }
                                    cout<<"prey: "<<prey<<endl;
                                    //eat function
                                    Eat(x, y, chessP, board, prey);
                                }
                            }
                        } while (!rMoves(x, y, chessP[test]));
                    }
                    //if Knight
                    else if (chessP[test].sym == 'N'){
                        do {
                            askMove(x, y, board);
                            //check if next move have a piece
                            //if have a piece then ...
                            if (checkLoad(x, y, board)){
                                //if white
                                if(checkcolor(x, y, board, person, who)){
                                    cout<<"SAME COLOR"<<endl;
                                }
                                //if black
                                else {
                                    //eat function
                                    //find the prey number
                                    //get piece num (test) *problem
                                    int prey=0;
                                    while (!checkPieceNum(x, y, chessP[prey])){
                                        prey++;
                                    }
                                    cout<<"prey: "<<prey<<endl;
                                    //eat function
                                    Eat(x, y, chessP, board, prey);
                                }
                            }
                        } while (!nMoves(x, y, chessP[test]));
                    }
                    //if Bishop
                    else if (chessP[test].sym == 'B'){
                        do {
                            askMove(x, y, board);
                            //check if next move have a piece
                            //if have a piece then ...
                            if (checkLoad(x, y, board)){
                                //if white
                                if(checkcolor(x, y, board, person, who)){
                                    cout<<"SAME COLOR"<<endl;
                                }
                                //if black
                                else {
                                    //eat function
                                    //find the prey number
                                    //get piece num (test) *problem
                                    int prey=0;
                                    while (!checkPieceNum(x, y, chessP[prey])){
                                        prey++;
                                    }
                                    cout<<"prey: "<<prey<<endl;
                                    //eat function
                                    Eat(x, y, chessP, board, prey);
                                }
                            }
                        } while (!bMoves(x, y, chessP[test]));
                    }
                    //if Queen
                    else if (chessP[test].sym == 'Q'){
                        do {
                            askMove(x, y, board);
                            //check if next move have a piece
                            //if have a piece then ...
                            if (checkLoad(x, y, board)){
                                //if white
                                if(checkcolor(x, y, board, person, who)){
                                    cout<<"SAME COLOR"<<endl;
                                }
                                //if black
                                else {
                                    //eat function
                                    //find the prey number
                                    //get piece num (test) *problem
                                    int prey=0;
                                    while (!checkPieceNum(x, y, chessP[prey])){
                                        prey++;
                                    }
                                    cout<<"prey: "<<prey<<endl;
                                    //eat function
                                    Eat(x, y, chessP, board, prey);
                                }
                            }
                        } while (!qMoves(x, y, chessP[test]));
                    }
                    //if King
                    else if (chessP[test].sym == 'K'){
                        do {
                            askMove(x, y, board);
                            //check if next move have a piece
                            //if have a piece then ...
                            if (checkLoad(x, y, board)){
                                //if white
                                if(checkcolor(x, y, board, person, who)){
                                    cout<<"SAME COLOR"<<endl;
                                }
                                //if black
                                else {
                                    //eat function
                                    //find the prey number
                                    //get piece num (test) *problem
                                    int prey=0;
                                    while (!checkPieceNum(x, y, chessP[prey])){
                                        prey++;
                                    }
                                    cout<<"prey: "<<prey<<endl;
                                    //eat function
                                    Eat(x, y, chessP, board, prey);
                                }
                            }
                        } while (!kMoves(x, y, chessP[test]));
                    }

                } while (checkLoad(x, y, board));
                //place piece on board
                placePieces(chessP, board, a, b, x, y, test);
                printBoard(board);

                //next player
                who++;
                //go back to white player
                if (who>1){
                    who=0;
                }
            }
            cout<<"GAME OVER"<<endl;
            if (who==1){
                cout<<"White Player Wins"<<endl;
            }
            else {
                cout<<"Black Player Wins"<<endl;
            }

        }
        //if choice is 2 print maunal
        else if (choice == 2){
            //print manual
            userManual();
        }
        else if (choice == 3){
            cout<<"Thank you for playing"<<endl;
        }
        //else invalid
        else {
            cout<<"INVALID CHOICE"<<endl;
        }
    } while (choice!=3);

/*
    //game proper
    //"who" is to indicate the player number
    int n=0, who=0;
    //if the king is eaten GAME OVER
    while (chessP[15].positionX!=100 && chessP[31].positionX!=100){
        //Print the Who will move
        if (who==0){
            cout<<"White Player"<<endl;
        }
        else if (who==1) {
            cout<<"Black Player"<<endl;
        }
        //get the piece
        do {
            whatPiece(a, b, board);
        } while (!checkcolor(a, b, board, person, who));
        //get piece num (test) *problem
        test=0;
        while (!checkPieceNum(a, b, chessP[test])){
            test++;
        }
        cout<<test;
        //while next move is not empty
        do {
        //move Restrictions
            //If Piece is Pawn
            if (chessP[test].sym == 'P'){
                do {
                    //ask for the next move
                    askMove(x, y, board);
                    //if forward move, there should be no piece
                    if (x == chessP[test].positionX){
                        //check if there is a piece
                        if (checkLoad(x, y, board)){
                            cout<<"INVALID MOVE"<<endl;
                        }
                    }
                    //if diagonal move, there shoudl be enemy
                    else {
                        //check if there is a piece
                        if (checkLoad(x, y, board)){
                            //if same color
                            if(checkcolor(x, y, board, person, who)){
                                cout<<"SAME COLOR"<<endl;
                            }
                            //if other color
                            else {
                                //eat function
                                //find the prey number
                                int prey=0;
                                //find number of enemy piece
                                while (!checkPieceNum(x, y, chessP[prey])){
                                    prey++;
                                }
                                cout<<"prey: "<<prey<<endl;
                                //eat function
                                Eat(x, y, chessP, board, prey);
                            }
                        }
                        //if diagonal has no piece
                        else {
                            cout<<"INVALID MOVE!"<<endl;
                            //so that the move will be invalid
                            y = chessP[test].positionY+2;
                        }
                    }
                //else just place
                } while (!pMoves(x, y, chessP[test]));
            }
            //if Rook
            else if (chessP[test].sym =='R') {
                do {
                    askMove(x, y, board);
                    //check if next move have a piece
                    //if have a piece then ...
                    if (checkLoad(x, y, board)){
                        //if white
                        if(checkcolor(x, y, board, person, who)){
                            cout<<"SAME COLOR"<<endl;
                        }
                        //if black
                        else {
                            //eat function
                            //find the prey number
                            //get piece num (test) *problem
                            int prey=0;
                            while (!checkPieceNum(x, y, chessP[prey])){
                                prey++;
                            }
                            cout<<"prey: "<<prey<<endl;
                            //eat function
                            Eat(x, y, chessP, board, prey);
                        }
                    }
                } while (!rMoves(x, y, chessP[test]));
            }
            //if Knight
            else if (chessP[test].sym == 'N'){
                do {
                    askMove(x, y, board);
                    //check if next move have a piece
                    //if have a piece then ...
                    if (checkLoad(x, y, board)){
                        //if white
                        if(checkcolor(x, y, board, person, who)){
                            cout<<"SAME COLOR"<<endl;
                        }
                        //if black
                        else {
                            //eat function
                            //find the prey number
                            //get piece num (test) *problem
                            int prey=0;
                            while (!checkPieceNum(x, y, chessP[prey])){
                                prey++;
                            }
                            cout<<"prey: "<<prey<<endl;
                            //eat function
                            Eat(x, y, chessP, board, prey);
                        }
                    }
                } while (!nMoves(x, y, chessP[test]));
            }
            //if Bishop
            else if (chessP[test].sym == 'B'){
                do {
                    askMove(x, y, board);
                    //check if next move have a piece
                    //if have a piece then ...
                    if (checkLoad(x, y, board)){
                        //if white
                        if(checkcolor(x, y, board, person, who)){
                            cout<<"SAME COLOR"<<endl;
                        }
                        //if black
                        else {
                            //eat function
                            //find the prey number
                            //get piece num (test) *problem
                            int prey=0;
                            while (!checkPieceNum(x, y, chessP[prey])){
                                prey++;
                            }
                            cout<<"prey: "<<prey<<endl;
                            //eat function
                            Eat(x, y, chessP, board, prey);
                        }
                    }
                } while (!bMoves(x, y, chessP[test]));
            }
            //if Queen
            else if (chessP[test].sym == 'Q'){
                do {
                    askMove(x, y, board);
                    //check if next move have a piece
                    //if have a piece then ...
                    if (checkLoad(x, y, board)){
                        //if white
                        if(checkcolor(x, y, board, person, who)){
                            cout<<"SAME COLOR"<<endl;
                        }
                        //if black
                        else {
                            //eat function
                            //find the prey number
                            //get piece num (test) *problem
                            int prey=0;
                            while (!checkPieceNum(x, y, chessP[prey])){
                                prey++;
                            }
                            cout<<"prey: "<<prey<<endl;
                            //eat function
                            Eat(x, y, chessP, board, prey);
                        }
                    }
                } while (!qMoves(x, y, chessP[test]));
            }
            //if King
            else if (chessP[test].sym == 'K'){
                do {
                    askMove(x, y, board);
                    //check if next move have a piece
                    //if have a piece then ...
                    if (checkLoad(x, y, board)){
                        //if white
                        if(checkcolor(x, y, board, person, who)){
                            cout<<"SAME COLOR"<<endl;
                        }
                        //if black
                        else {
                            //eat function
                            //find the prey number
                            //get piece num (test) *problem
                            int prey=0;
                            while (!checkPieceNum(x, y, chessP[prey])){
                                prey++;
                            }
                            cout<<"prey: "<<prey<<endl;
                            //eat function
                            Eat(x, y, chessP, board, prey);
                        }
                    }
                } while (!kMoves(x, y, chessP[test]));
            }

        } while (checkLoad(x, y, board));
        //place piece on board
        placePieces(chessP, board, a, b, x, y, test);
        printBoard(board);

        //next player
        who++;
        //go back to white player
        if (who>1){
            who=0;
        }
    }
    cout<<"GAME OVER"<<endl;
    if (who==1){
        cout<<"White Player Wins"<<endl;
    }
    else {
        cout<<"Black Player Wins"<<endl;
    }
*/
/*
    // get what the player wants
    whatPiece(a, b, board);
    if (checkLoad(a, b, board)){
        //coordinates of player input
        cout<<"hi:"<<a<<","<<b<<endl;
    }
    //the move
    askMove(x, y, board);
    //check if valid move
    if (chessP[2].rightMoves(a, b, x, y)){
        cout<<"yehey"<<endl;
    }
    placePieces(chessP, board, a, b, x, y);
    printBoard(board);

*/
}
