#include <iostream>
using namespace std;

int main(){
    double G = 6.67e-11;
    double m1 = 10;
    double m2 = 5.92e24;
    double r = 6.371e6;
    double F = G*(m1*m2)/(r*r);
    //cout << F << endl;
    // F = ma => a = F/m1
    double a = F/m1;
    cout << a << endl;

}