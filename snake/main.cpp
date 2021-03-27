#include <iostream>
using namespace std;

const int width = 40;
const int height = 20;

void draw(){
    //Drawing the top border
    for (int i=0; i<width+1; i++) {
        cout << "#";
    }
    cout << endl;

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
    for (int i=0; i<width+1; i++) {
        cout << "#";
    }
    cout << endl;
}


int main(int argc, const char * argv[]) {
    draw();
    return 0;
}
