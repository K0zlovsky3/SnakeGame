#include "Core/Difficulty/Difficulty.h"
#include <iostream>
#include <cstdlib>

int DifficultySet() {
    int d = 0;
    std::cout << "Difficulty:\n";
    std::cout << "1 - Easy\n";
    std::cout << "2 - Medium\n";
    std::cout << "3 - Hard\n";
    std::cin >> d;
    system("cls");

    if (d == 1) return 150;
    if (d == 3) return 50;
    return 90;
}
