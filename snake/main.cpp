#include <iostream>
#include <ncurses.h>

bool gameOver;
const int width = 40;
const int height = 20;
int x, y, fruitX, fruitY, score;
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;


//Function to draw the horizontal line of + symbols
void DrawLine(int lineLength){
    for (int i=0; i<lineLength+1; i++) {
        printw("+");
    }
}

void FruitGenerator(){
    fruitX = rand() % width;
    fruitY = rand() % height;
}

void Setup(){
    gameOver = false;
    score = 0;
    dir = STOP;
    x = width / 2 - 1;
    y = height / 2 - 1;
    FruitGenerator();
    
    //Initializing everything for ncurse
    initscr();
    clear();
    noecho();
    cbreak();
    curs_set(0);
}

void Draw(){
    clear();
    //Drawing the top border
    DrawLine(width);
    
    for (int i = 0; i < height; i++) {
        for (int j = 0 ; j < width; j++) {
            if (j == 0 | j == width - 1) {
                printw("+");
            } else if (i == y && j == x) {
                printw("O");
            } else if (i == fruitY && j == fruitX ) {
                printw("F");
            } else {
                printw(" ");
            }
        }
        printw("\n");
    }
    
    //Drawing the bottom border
    DrawLine(width);
    
    printw("Score is: %d", score);
    refresh();
}

void Input(){
    keypad(stdscr, true);
    halfdelay(1);
    
    //Getting a char
    int c = getch();
    switch (c) {
        case KEY_LEFT:
            dir=LEFT;
            break;
        case KEY_RIGHT:
            dir=RIGHT;
            break;
        case KEY_UP:
            dir=UP;
            break;
        case KEY_DOWN:
            dir=DOWN;
            break;
        case 113:
            gameOver=true;
            break;
    }
}

void Logic(){
    
    //Handling the actual movement
    switch (dir) {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
    }
    
    //Border collision check
    if (x > width || x < 1 || y > height || y < 1) {
        gameOver = true;
    }
    
    //Fruit eating logic
    if (x == fruitX && y == fruitY) {
        score++;
        FruitGenerator();
    }
}

int main(int argc, const char * argv[]) {
    Setup();
    while (!gameOver) {
        Draw();
        Logic();
        Input();
    }
    getch();
    endwin();
    
    return 0;
}
