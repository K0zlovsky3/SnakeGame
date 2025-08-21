#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <random> // Генератор случайных чисел
#include "Board.h"
#include "Snake.h"

extern int playerX;
extern int playerY;

Axis fruit;
//extern int snakelenght;

void Fruits() {
	fruit.x = rand() % 20;
	fruit.y = rand() % 20;
}

//void Check_Fruit() {
//	if (playerX == fruitX && playerY == fruitY) {
//		snakelenght++;
//		Fruits();
//	}
//}
