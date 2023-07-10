#ifndef SNAKE_H
#define SNAKE_H

#include <windows.h>
#include <vector>

#define WIDTH 50
#define HEIGHT 25

using namespace std;

class Snake
{
    private:
        COORD pos;
        float v;
        char d;
        int l;
        vector<COORD> body;

    public:
        Snake(COORD pos, int v);

        void grow();
        void move_snake();
        void changeDir(char dir);

        vector<COORD> get_body();

        bool collided();
        bool eaten(COORD food);

        COORD get_pos();
};

#endif // SNAKE_H
