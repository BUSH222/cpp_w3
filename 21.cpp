#include <iostream>
using namespace std;

int main() {
    string ar[4] = {"Element one", "two", "three", "four"};
    cout << ar[0] << endl;
    for (string i: ar){
        cout << i << endl;
    }
    cout << endl;
    ar[2] = "THREE";
    for (string i: ar){
        cout << i << endl;
    }

    cout << sizeof(ar) / sizeof(ar[0]);

}