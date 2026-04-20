#include <iostream>
#include <cmath>
using namespace std;

class ComplexNumber{
    public:
        double real;
        double imag;
        ComplexNumber(){real = 0; imag = 0;}
        ComplexNumber(short r, short i){real = (double)r; imag = (double)i;}
        ComplexNumber(int r, int i){real = (double)r; imag = (double)i;}
        ComplexNumber(float r, float i){real = (float)r; imag = (float)i;}
        ComplexNumber(double r, double i){real = r; imag = i;}

        double r() const{
            return sqrt(real*real+imag*imag);
        }
        double arg() const{
            return atan2(imag, real);
        }

        bool operator==(const ComplexNumber& other) const {
            return real == other.real && imag == other.imag;
        }

        bool operator!=(const ComplexNumber& other) const {
            return !(*this == other);
        }

        bool operator<(const ComplexNumber& other) const {
            return r() < other.r();
        }

        bool operator>(const ComplexNumber& other) const {
            return r() > other.r();
        }

        bool operator<=(const ComplexNumber& other) const {
            return r() <= other.r();
        }

        bool operator>=(const ComplexNumber& other) const {
            return r() >= other.r();
        }

        ComplexNumber operator+(const ComplexNumber& other) const {
            return ComplexNumber(real + other.real, imag + other.imag);
        }
        ComplexNumber operator-(const ComplexNumber& other) const {
            return ComplexNumber(real - other.real, imag - other.imag);
        }
        ComplexNumber operator*(const ComplexNumber& other) const {
            return ComplexNumber(real*other.real - imag*other.imag, real*other.imag + imag*other.real);
        }
        ComplexNumber operator/(const ComplexNumber& other) const {
            double denominator = other.real*other.real + other.imag*other.imag;
            return ComplexNumber((real*other.real + imag*other.imag) / denominator, (imag*other.real - real*other.imag) / denominator);
        }

        ComplexNumber operator+=(const ComplexNumber& other){
            *this = *this + other;
            return *this;
        }
        


        void print() const{
            if(imag >= 0){
                cout << real << " + " << imag << "i" << endl;
            } else {
                cout << real << imag << "i" << endl;
            }
        }
        void printpolar() const {
            cout << "mag: " << r() << " " << "arg: " << arg() << endl;; 
        }
};

int main(){
    ComplexNumber a(1, -3);
    a.print();
    // a.printpolar();
    ComplexNumber b(2, 5);
    b.print();
    cout << "which is bigger?" << endl;
    if (a > b) {cout << "a is bigger at a mag of " << a.r() << endl;}
    else if (a > b) {cout << "a and b are the same at a mag of " << a.r() << endl;}
    else if (a < b) {cout << "b is bigger at a mag of " << b.r() << endl;}
    a.print();
    a += b;
    a += b;
    a.print();
    cout << "which is bigger?" << endl;
    if (a > b) {cout << "a is bigger at a mag of " << a.r() << endl;}
    else if (a > b) {cout << "a and b are the same at a mag of " << a.r() << endl;}
    else if (a < b) {cout << "b is bigger at a mag of " << b.r() << endl;}

    return 0;
}