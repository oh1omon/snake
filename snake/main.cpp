#include <iostream>
#include <ncurses.h>

bool gameOver;
const int width = 40;
const int height = 20;
int x, y, fruitX, fruitY, score;
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;


//Function to draw the horizontal line of # symbols
void DrawLine(int lineLength){
    for (int i=0; i<lineLength+1; i++) {
        printw("#");
    }
    printw("\n");
}

void Setup(){
    gameOver=false;
    dir = STOP;
    x = width / 2 - 1;
    y = height / 2 - 1;
    fruitX = rand() % width;
    fruitY = rand() % height;
    
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
    
    for (int i=0; i<height; i++) {
        for (int j = 0 ; j<width; j++) {
            if (j==0 || j==width-1) {
                printw("#");
            }
            if (i == y && j == x) {
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
    
    printw("Score is: ", score);
    refresh();
    getch();
    endwin();
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
            
        default:
            break;
    }
}


int main(int argc, const char * argv[]) {
    Setup();
    Draw();
    //    Setup();
    //    while (!gameOver) {
    //        Draw();
    //    }
//    initscr();
//    printw("Enter a character: ");
//    refresh();
//    getch();
//    refresh();
//
    return 0;
}
