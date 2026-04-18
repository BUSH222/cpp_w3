#include <iostream>
#include <string>
using namespace std;

int main() {
    string daystr;
    getline(cin, daystr);
    int day = stoi(daystr);

    switch (day) {
        case 1:
            cout << "m";
            break;
        case 2:
            cout << "tu";
            break;
        case 3:
            cout << "we";
            break;
        case 4:
            cout << "th";
            break;
        case 5:
            cout << "fr";
            break;
        case 6:
            cout << "sa";
            break;
        case 7:
            cout << "su";
            break;
        default:
            cout << "gg";
            break;
    }

}