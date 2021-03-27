#include <iostream>
using namespace std;

bool gameOver;
const int width = 40;
const int height = 20;
int x, y, fruitX, fruitY, score;

void ClearTerminal(){
    for (int i = 0; i<100; i++) {
        cout<< "\n";
    }
}

//Function to draw the horizontal line of # symbols
void DrawLine(int lineLength){
    for (int i=0; i<lineLength+1; i++) {
        cout << "#";
    }
    cout << endl;
}

void Setup(){
    gameOver=false;
    x = width/2;
    y = width/2;
    fruitX = rand() % width;
    fruitY = rand() % height;
 }

void Draw(){
    //Clearing the terminal
    ClearTerminal();
    //Drawing the top border
    DrawLine(width);

    for (int i=0; i<height; i++) {
        for (int j = 0 ; j<width; j++) {
            if (j==0 || j==width-1) {
                cout << "#";
            }
            cout << " ";
        }
        cout << endl;
    }
    
    //Drawing the bottom border
    DrawLine(width);
}


int main(int argc, const char * argv[]) {
    Setup();
    while (!gameOver) {
        Draw();
    }
    return 0;
}
