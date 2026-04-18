#include <iostream>
using namespace std;

int main(){
    int numbers[5] = {1, 2, 3, 4, 5};
    for (int num: numbers){
        cout << num << endl;
    }
    string bruh = "brbrurburuhepstein";
    for (char c: bruh) {
        cout << c << ' ';
    }
}