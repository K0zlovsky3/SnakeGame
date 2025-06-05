#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

const int cell_size = 20; // размер ячейки
const int width = 400; // ширина поля
const int height = 400; // высота поля

// размер одной ячейки в строке и столбце

const int cols = width / cell_size; 
const int rows = height / cell_size;

char field[rows][cols];

int playerY = 10; // координаты по Y
int playerX = 5; // координаты по X
int dy = 0; // направление по Y
int dx = 1; // направление по X

void DifficultySet();
void DrawBoard();
void InitBoard();

int main()
{
    setlocale(0, "");
    bool isRunning = true;

    DifficultySet();
    InitBoard();
    DrawBoard();

    while (isRunning) {
        if (_kbhit()) { // _kbhit проверка ввода без прекращении программы

/* если это реализация со стрелками то _getch будет брат два значения. Первое это байт - 224 код клавиши,
а второе это байт который отвечает за то, какая именно стрелка. Up - 72, Down - 80, Left - 75, Right - 77
Сейчас сделал так, чтобы движение зацикливалось с помощью %, таким образом не получится превысить максимальное значение*/
            
            int ch = _getch(); // считывание клавиши ввода
            if (ch == 224) {
                int arrow = _getch();
                switch (arrow) {
                case 72: // ↑ уменьшает Y (вверх)
                    dx = 0; dy = -1;
                    break;
                case 80: // ↓ увеличивает Y (вниз)
                    dx = 0; dy = 1;
                    break;
                case 75: // ← уменьшает X (влево)
                    dx = -1; dy = 0;
                    break;
                case 77: // → увеличивает X (вправо)
                    dx = 1; dy = 0;
                    break;
                }
            }
            else if (ch == 'q') {
                isRunning = false;
            }
        }

        playerX = (playerX + dx + cols) % cols;
        playerY = (playerY + dy + rows) % rows;

        InitBoard();
        DrawBoard();

        Sleep(200); // тик: пауза между обновлениями
    }
}
       

void DifficultySet() {
    int d;
    std::cout << "Difficult:" << std::endl;
    std::cout << "1 - Easy" << std::endl;
    std::cout << "2 - Medium" << std::endl;
    std::cout << "3 - Hard" << std::endl;
    std::cin >> d;
    // необходимо добавить функцию различных видов сложностей возможно .h файл
    system("cls");
}

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
        for (int x = 0; x < cols; x++)
            std::cout << field[y][x] << ' ';
    }
    std::cout << std::endl;
}

