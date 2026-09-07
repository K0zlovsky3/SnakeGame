#pragma once

#include "Core/Board/Board.h"
#include <deque>

void InitSnake();
void SetDirection(int ndx, int ndy);
Point Head();
Point NextHead();
void Step(bool grow);
bool Occupies(Point p);
const std::deque<Point>& Body();
