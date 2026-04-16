#include <iostream>
using namespace std;

int main() {
    int fibonacci[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int a = 1;
    int b = 1;
    int c = 0;
    int counter = 0;
    for (int num: fibonacci){
        fibonacci[counter] = a;
        c = b+a;
        a = b;
        b = c;
        counter++;
    }



    for (int elem: fibonacci){
        cout << elem << endl;
    }
}