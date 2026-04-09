#include <iostream>
using namespace std;

int main() {
    string a = "abcdefg";
    a = a.append("00000");
    cout << a.length();
}