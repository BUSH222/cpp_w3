#include <iostream>
using namespace std;

int main() {
    string a = "123456789";
    cout << a[0] << endl;
    cout << a[a.length()-1] << endl;
    a[0] = 's';
    cout << a << endl;
}
