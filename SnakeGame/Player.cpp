#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include "Board.h"

void DrawBoard();
void InitBoard();
void PlayBoard();

extern int playerX;
extern int playerY;
extern const int cols;
extern const int rows;

int dy = 0; // направление по Y
int dx = 1; // направление по X

bool isRunning = true;

void PlayBoard() {
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

        Sleep(90); // тик: пауза между обновлениями
    }
}
