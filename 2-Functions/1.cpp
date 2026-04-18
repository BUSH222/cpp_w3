#include <iostream>
using namespace std;

// Task: Array Manipulation Program
// Write the following functions to pass the tests in main()

// 1. Function that takes an array and size, returns sum (pass by value)
int sumArray(int arr[], int size){
    int result = 0;
    for (int i = 0; i<size; i++){
        result += arr[i];
    }
    return result;
};

// 2. Function that takes array by pointer, modifies elements by doubling them
void doubleArrayElements(int* arr, int size){
    for(int i = 0; i < size; i++){
        arr[i] *= 2;
    }
};

// 3. Function that takes array by reference, finds and returns max value
int findMax(int (&arr)[5]){
    int m = arr[0];
    for (int i = 1; i<5; i++){
        if (m < arr[i]){
            m = arr[i];
        }
    }
    return m;
};  // Reference to array of size 5

// 4. Function that swaps two integers using pointers
void swapValues(int* a, int* b){
    int c = *a;
    *a = *b;
    *b = c;
};

// 5. Function that reverses an array in place using pointers
void reverseArray(int* arr, int size){
    int temp = 0;
    for (int i = 0; i < ceil(size/2); i++){
        temp = arr[i];
        arr[i] = arr[size-i-1];
        arr[size-i-1] = temp;
    }
};

// 6. Function that prints array using pointer arithmetic
void printArray(const int* arr, int size){
    for (int i = 0; i<size; i++){
        cout << arr[i] << ' ';
    }
    cout << endl;
};

// 7. Function that counts occurrences of a value in array
int countOccurrences(int arr[], int size, int target){
    int targetcount = 0;
    for (int i = 0; i<size; i++){
        if (arr[i] == target) {targetcount++;}
    }
    return targetcount;
};

// 8. Function that takes reference and modifies original array by shifting elements
void shiftLeft(int (&arr)[5], int positions){
    int arrcopy[5] = {0, 0, 0, 0, 0};
    for(int i = 0; i < 5; i++){
        arrcopy[i] = arr[i];
    }
    for(int i = 0; i<5; i++){
        if (i+positions > 4){
            arr[i] = arrcopy[i+positions-5];
        } else {
            arr[i] = arrcopy[i+positions];
        }
    } // 0 -> 0-2+5 = 3
};

int main() {
    // Test Case 1: sumArray
    int arr1[] = {1, 2, 3, 4, 5};
    cout << "Sum: " << sumArray(arr1, 5) << endl;  // Expected: 15
    
    // Test Case 2: doubleArrayElements (modifies original)
    int arr2[] = {1, 2, 3, 4, 5};
    doubleArrayElements(arr2, 5);
    printArray(arr2, 5);  // Expected: 2 4 6 8 10
    
    // Test Case 3: findMax with reference
    int arr3[5] = {3, 7, 2, 9, 1};
    cout << "Max: " << findMax(arr3) << endl;  // Expected: 9
    
    // Test Case 4: swapValues
    int x = 10, y = 20;
    swapValues(&x, &y);
    cout << "After swap - x: " << x << " y: " << y << endl;  // Expected: 20 10
    
    // Test Case 5: reverseArray using pointers
    int arr4[] = {1, 2, 3, 4, 5};
    reverseArray(arr4, 5);
    printArray(arr4, 5);  // Expected: 5 4 3 2 1
    
    // Test Case 6: countOccurrences
    int arr5[] = {1, 2, 2, 3, 2, 4, 2};
    cout << "Count of 2: " << countOccurrences(arr5, 7, 2) << endl;  // Expected: 4
    
    // Test Case 7: shiftLeft with reference
    int arr6[5] = {10, 20, 30, 40, 50};
    shiftLeft(arr6, 2);
    printArray(arr6, 5);  // Expected: 30 40 50 10 20
    
    return 0;
}

// Implement all 8 functions below this line