#include <iostream>
#include "MazeGame.h"
#include "DesignPatterns.h"
#include <ctime>
using namespace std;

int main(){
    srand( time( 0 ) );
    MazeGame* mazeGame = new MazeGame;
    mazeGame->startGame(Singleton);
    return 0;
}
