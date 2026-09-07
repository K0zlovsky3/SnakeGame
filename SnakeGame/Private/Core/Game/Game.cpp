#include "Core/Game/Game.h"
#include "Core/Board/Board.h"
#include "Core/Difficulty/Difficulty.h"
#include "Core/Player/Snake.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <Windows.h>

static Point food;

static void SpawnFood() {
    // ponytail: retry random cells; switch to an empty-cell list if the board is nearly full
    do {
        food = { rand() % cols, rand() % rows };
    } while (GetCell(food) == '#' || Occupies(food));
}

static void HandleInput(bool& running) {
    if (!_kbhit())
        return;

    int ch = _getch();
    if (ch == 224) {
        switch (_getch()) {
        case 72: SetDirection(0, -1); break;
        case 80: SetDirection(0, 1); break;
        case 75: SetDirection(-1, 0); break;
        case 77: SetDirection(1, 0); break;
        }
    }
    else if (ch == 'q' || ch == 'Q') {
        running = false;
    }
}

static void Render(int score) {
    ClearBoard();
    SetCell(food, '*');
    const auto& body = Body();
    for (size_t i = 0; i < body.size(); i++)
        SetCell(body[i], i == 0 ? '0' : 'o');
    DrawBoard();
    std::cout << "Score: " << score << "   (q = quit)\n";
}

void RunGame() {
    srand(static_cast<unsigned>(time(nullptr)));

    const int delay = DifficultySet();
    InitBoard();
    InitSnake();
    SpawnFood();

    bool running = true;
    int score = 0;
    Render(score);

    while (running) {
        HandleInput(running);
        if (!running)
            break;

        const Point next = NextHead();
        const bool grow = next == food;
        const Point tail = Body().back();

        if (GetCell(next) == '#' || (Occupies(next) && !(!grow && next == tail))) {
            Render(score);
            std::cout << "Game over. Score: " << score << '\n';
            break;
        }

        Step(grow);
        if (grow) {
            score++;
            SpawnFood();
        }

        Render(score);
        Sleep(delay);
    }
}
