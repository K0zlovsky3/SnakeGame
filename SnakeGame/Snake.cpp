#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <vector>
#include "Board.h"
#include "Snake.h"

extern int playerX;
extern int playerY;

std::vector <Axis> snake;

//int snakelenght = 1;

void SnakeInit(int startX, int startY, int lenght) {
	snake.clear();
	for (int i = 0; i < lenght; i++) {
		snake.push_back({ startX - i, startY });
	}
}

void SnakeDebug() {
	std::cout << "Snake [" << snake.size() << " segments]: ";
	for (int i = 0; i < snake.size(); i++) {
		std::cout << "[" << snake[i].x << "," << snake[i].y << "]";
		if (i == 0) std::cout << " <- HEAD";
		std::cout << " ";
	}
	std::cout << std::endl;
}