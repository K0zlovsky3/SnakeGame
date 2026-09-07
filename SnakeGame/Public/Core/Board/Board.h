#pragma once

struct Point {
    int x = 0;
    int y = 0;
    bool operator==(const Point& o) const { return x == o.x && y == o.y; }
};

extern const int cols;
extern const int rows;

void InitBoard();
void ClearBoard();
void SetCell(Point p, char c);
char GetCell(Point p);
void DrawBoard();
