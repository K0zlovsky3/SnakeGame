#include <iostream>
#include <stdlib.h>
#include <conio.h>

const int cell_size = 20; // размер ячейки
const int width = 400; // ширина поля
const int height = 400; // высота поля

// размер одной ячейки в строке и столбце

extern const int cols = width / cell_size;
extern const int rows = height / cell_size;

char field[rows][cols];

int playerY = 10; // координаты по Y
int playerX = 5; // координаты по X

// заполнение двумерного массива точками, размещение стены и игрока
void InitBoard() {
    for (int y = 0; y < rows; y++)
        for (int x = 0; x < cols; x++)
            field[y][x] = '.';

    field[3][3] = '#';
    field[playerY][playerX] = '0';
}

// вывод поля
void DrawBoard() {
    system("cls");
    for (int y = 0; y < rows; y++) {
        if (y == 0) // доп.условие чтоб не было лишнего пробела
            continue;
        else
            std::cout << std::endl; // нужно было добавить перенос в нужном месте по y
        for (int x = 0; x < cols; x++)
            std::cout << field[y][x] << " ";
    }
    std::cout << std::endl;
}