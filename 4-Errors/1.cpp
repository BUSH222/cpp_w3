#include <iostream>
#include <string>
using namespace std;

/*
    TASK: Learn Exception Handling with try/throw/catch
    
    In C++, exception handling allows you to gracefully handle errors that occur
    during program execution. The three key keywords are:
    
    1. try { ... }
       - The try block contains code that might throw an exception
       - Wrap risky operations here (division by zero, invalid operations, etc.)
    
    2. throw
       - Throws an exception when an error condition is detected
       - You can throw built-in types (int, double, string) or custom exception objects
       - Example: throw "Error: Division by zero!";
    
    3. catch (type parameter) { ... }
       - Catches and handles the exception thrown from the try block
       - The type must match the thrown exception type (or be a parent class)
       - Multiple catch blocks can be chained to handle different exception types
       - catch (...) catches any exception type
    
    BASIC STRUCTURE:
    
    try {
        // code that might throw an exception
        if (error_condition) {
            throw exception_value;
        }
    }
    catch (exception_type e) {
        // handle the exception
        cout << "Caught exception: " << e << endl;
    }
    
    TODO: Write a program that:
    1. Asks the user for two numbers
    2. Performs division inside a try block
    3. Throws an exception if attempting to divide by zero
    4. Catches the exception and displays an error message
    5. Demonstrates catching different exception types (optional challenge)
*/

int main(){
    double num1, num2;
    string unparsednums, unparsed1, unparsed2;
    cout << "Give me two numbers: " << endl;
    bool addto2nd = false;
    try {
        getline(cin, unparsednums);
        for (int i = 0; i < unparsednums.size(); i++){
            if (unparsednums[i] == ' ' || unparsednums[i] == '\n'){
                addto2nd = true;
                continue;
            }

            if (!(isdigit(unparsednums[i]) || unparsednums[i] == '.'))
                throw 0;

            if (!addto2nd){
                unparsed1 += unparsednums[i];
            } else {
                unparsed2 += unparsednums[i];
            }
        }
        if (!addto2nd) throw 2;
        
        num1 = stod(unparsed1);
        num2 = stod(unparsed2);
        if (num2 == 0) throw 1;
        cout << endl;
        cout << num1/num2 << endl;
    } catch (int err) {
        string errstr;
        switch (err){
            case 0: errstr = "invalid character in input"; break;
            case 1: errstr = "division by zero"; break;
            case 2: errstr = "one number specified"; break;
            default: errstr = "UNKNWN";
        }
        cout << "ERROR: " << errstr << endl;
    } catch (...){
        cout << "ERROR: UNKNWN" << endl;
    }
}