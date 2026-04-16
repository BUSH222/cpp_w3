#include <iostream>
#include <string>

using namespace std;

int main() {
    int a = 12;
    int b = 12;
    cout << ((a > b) ? "greater" : "less") << endl;
    string message = (a > b)? "greater" : 
        (a == b)? "equal" :
        (a < b)? "less" : "idk";
    cout << message;

}