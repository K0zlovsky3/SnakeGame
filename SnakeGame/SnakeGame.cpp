#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include "Board.h"
#include "Difficulty.h"
#include "Player.h"

int main()
{
    setlocale(0, "");
    DifficultySet();
    InitBoard();
    DrawBoard();
    PlayBoard();
}