#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <vector>
#include "Fruits.h"
#include "Snake.h"
#include "PlayBoard.h"

const int cell_size = 20; // размер ячейки
const int width = 400; // ширина поля
const int height = 400; // высота поля

// externs

// размер одной ячейки в строке и столбце
extern const int cols = width / cell_size;
extern const int rows = height / cell_size;

//extern int fruitX;
//extern int fruitY;

extern std::vector <Axis> snake;

extern bool isRunning;

extern int dy, dx;

char field[rows][cols];

//int playerY = 10; // координаты по Y
//int playerX = 5; // координаты по X

// заполнение двумерного массива точками, размещение стены и игрока
void InitBoard() {
    for (int y = 0; y < rows; y++)
        for (int x = 0; x < cols; x++)
            field[y][x] = '.';

    field[fruit.x][fruit.y] = '*';

    for (int i = 1; i < snake.size(); i++)
        field[snake[i].y][snake[i].x] = 'o';

    field[snake[0].y][snake[0].x] = 'O';
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

void Tick() {
    Axis newHead = { (snake[0].x + dx + cols) % cols, (snake[0].y + dy + rows) % rows };

    for (int i = 0; i < snake.size(); i++) {
        if (snake[i].x == newHead.x && snake[i].y == newHead.y) {
            isRunning = false;
            return;
        }
    }

    snake.insert(snake.begin(), newHead);

    if (newHead.x == fruit.x && newHead.y == fruit.y) {
        Fruits();
    }
    else {
        snake.pop_back();
    }
    InitBoard();
}