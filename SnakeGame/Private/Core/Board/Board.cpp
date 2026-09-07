#include "Core/Board/Board.h"
#include <iostream>
#include <cstdlib>

const int cell_size = 20;
const int width = 400;
const int height = 400;

extern const int cols = width / cell_size;
extern const int rows = height / cell_size;

char field[rows][cols];

static void PlaceWalls() {
    field[3][3] = '#';
}

void InitBoard() {
    for (int y = 0; y < rows; y++)
        for (int x = 0; x < cols; x++)
            field[y][x] = '.';
    PlaceWalls();
}

void ClearBoard() {
    for (int y = 0; y < rows; y++)
        for (int x = 0; x < cols; x++)
            if (field[y][x] != '#')
                field[y][x] = '.';
}

void SetCell(Point p, char c) {
    field[p.y][p.x] = c;
}

char GetCell(Point p) {
    return field[p.y][p.x];
}

void DrawBoard() {
    system("cls");
    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++)
            std::cout << field[y][x] << ' ';
        std::cout << '\n';
    }
}
