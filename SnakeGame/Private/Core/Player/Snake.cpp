#include "Core/Player/Snake.h"

static std::deque<Point> body;
static int dx = 1;
static int dy = 0;

void InitSnake() {
    dx = 1;
    dy = 0;
    body = { {5, 10}, {4, 10}, {3, 10} };
}

void SetDirection(int ndx, int ndy) {
    if (body.size() > 1 && ndx == -dx && ndy == -dy)
        return;
    dx = ndx;
    dy = ndy;
}

Point Head() {
    return body.front();
}

Point NextHead() {
    Point h = body.front();
    return { (h.x + dx + cols) % cols, (h.y + dy + rows) % rows };
}

void Step(bool grow) {
    body.push_front(NextHead());
    if (!grow)
        body.pop_back();
}

bool Occupies(Point p) {
    for (const Point& c : body)
        if (c == p)
            return true;
    return false;
}

const std::deque<Point>& Body() {
    return body;
}
