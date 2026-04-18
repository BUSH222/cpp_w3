#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Task: Mathematical Utilities with Advanced Function Concepts
// Implement all 8 functions below to pass the test cases

// Global variable to track function calls
int functionCallCount = 0;

// 1. Function overloading: implement calculate() for int and double parameters
// Should perform arithmetic operations: '+', '-', '*', '/'
int calculate(int a, int b, char op){
    switch (op){
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
        default: return a+b;
    }
};

double calculate(double a, double b, char op){
    switch (op){
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
        default: return a+b;
    }
};

// 2. Recursion: calculate factorial of a number
// factorial(5) should return 120, factorial(0) should return 1
int factorial(int n){
    if (n == 0 || n == 1){
        return 1;
    } else {
        return factorial(n-1)*n;
    }
};

// 3. Recursion: calculate nth Fibonacci number
// fibonacci(6) should return 8, fibonacci(7) should return 13
int fibonacci(int n){
    if (n == 0){
        return 0;
    } else if (n == 1){
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
};

// 4. Scope demonstration: print local variable and global functionCallCount
void demonstrateScope(int localVar){
    cout << localVar << endl;
    cout << functionCallCount << endl;
};

// 5. Pass by reference: add a value to vector multiple times
void expandVector(vector<int>& vec, int value, int times){
    for (int i = 0; i < times; i++){
        vec.push_back(value);
    }
};

// 6. Pass by pointer: reverse a C-style string in place
void reverseString(char* str, int length){
    char temp;
    for (int i = 0; i < ceil(length/2.0); i++){
        temp = str[i];
        str[i] = str[length-i-1];
        str[length-i-1] = temp;
    }
};

// 7. Lambda inside function: sort vector in descending order and print values above threshold
void processNumbers(vector<int>& nums, int threshold){
    sort(nums.begin(), nums.end(), [](int a, int b) { return a > b; });
    for (int i: nums){
        if (i > threshold){
            cout << i << ' ';
        }
    }
    cout << endl;
};

// 8. Recursion with references: find all paths that sum to target using numbers 1 to remaining
void sumToTarget(int current, int target, vector<int>& path, int remaining) {
    if (current == target) {
        for (int x : path) cout << x << " ";
        cout << endl;
        return;
    }
    if (current > target || remaining <= 0) return;

    for (int i = remaining; i >= 1; --i) {
        path.push_back(i);

        sumToTarget(current + i, target, path, i);

        path.pop_back();
    }
}

int main() {
    cout << "=== Test Case 1: Function Overloading ===" << endl;
    cout << "5 + 3 = " << calculate(5, 3, '+') << endl;          // Expected: 8
    cout << "5.5 + 2.3 = " << calculate(5.5, 2.3, '+') << endl;  // Expected: 7.8
    cout << "10 * 4 = " << calculate(10, 4, '*') << endl;        // Expected: 40
    cout << "9.0 / 3.0 = " << calculate(9.0, 3.0, '/') << endl;  // Expected: 3.0
    
    cout << "\n=== Test Case 2: Recursion - Factorial ===" << endl;
    cout << "Factorial of 5: " << factorial(5) << endl;  // Expected: 120
    cout << "Factorial of 0: " << factorial(0) << endl;  // Expected: 1
    
    cout << "\n=== Test Case 3: Recursion - Fibonacci ===" << endl;
    cout << "Fibonacci(6): " << fibonacci(6) << endl;  // Expected: 8
    cout << "Fibonacci(7): " << fibonacci(7) << endl;  // Expected: 13
    
    cout << "\n=== Test Case 4: Scope ===" << endl;
    int localVar = 42;
    demonstrateScope(localVar);
    
    cout << "\n=== Test Case 5: Pass by Reference ===" << endl;
    vector<int> myVec = {1, 2, 3};
    expandVector(myVec, 5, 3);
    cout << "Vector after expansion: ";
    for (int val : myVec) cout << val << " ";  // Expected: 1 2 3 5 5 5
    cout << endl;
    
    cout << "\n=== Test Case 6: Pass by Pointer ===" << endl;
    char message[] = "HELLO";
    reverseString(message, 5);
    cout << "Reversed string: " << message << endl;  // Expected: OLLEH
    
    cout << "\n=== Test Case 7: Lambda Functions ===" << endl;
    vector<int> numbers = {15, 3, 42, 8, 19, 7};
    processNumbers(numbers, 10);  // Expected: sorted descending, then print > 10
    
    cout << "\n=== Test Case 8: Recursion with References ===" << endl;
    cout << "Finding paths that sum to 6 using values 1-3:" << endl;
    vector<int> path;
    sumToTarget(0, 6, path, 3);
    
    cout << "\n=== Function Call Count ===" << endl;
    cout << "Total calculate() calls: " << functionCallCount << endl;
    
    return 0;
}

// Implement all 8 functions below this line
