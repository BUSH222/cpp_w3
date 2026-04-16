#include <iostream>
#include <string>
using namespace std;

int main() {
    string age1, age2;
    getline(cin, age1);
    getline(cin, age2);
    int age1int = stoi(age1);
    int age2int = stoi(age2);
    if (age1int < age2int) {
        cout << "age 1 is less" << endl;
    } else if (age1int == age2int) {
        cout << "ages equal" << endl;
    } else {
        cout << "age 2 is less" << endl;
    }
    if (!(age1int < age2int)) {
        cout << "not age 1 is less" << endl;
    }
    if (age1int > 18 && age2int > 18) {
        cout << "both > 18";
    }
    if (age1int > 18 || age2int > 18) {
        cout << "either > 18";
    }

}
