#include <iostream>
using namespace std;

class Book{
    public:
        string title;
        string author;
        int year;
};

int main(){
    Book book1;
    book1.title = "title1";
    book1.author = "aaaa";
    book1.year = 1234;

    cout << book1.title<< endl;
    cout << book1.author<< endl;
    cout << book1.year<< endl;

    return 0;

}