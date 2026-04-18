#include <iostream>
using namespace std;

int main() {
    int matrix1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    int matrix2[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1},
    };
    int matrix1size[2] = {3, 3};
    int matrix2size[2] = {3, 3};

    int matrixout[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0},
    };

    for (int i = 0; i < matrix1size[0]; i++) {
        for (int j = 0; j < matrix1size[1]; j++) {
            matrixout[i][j] = matrix1[i][j] + matrix2[i][j];
        };
    };

    for (auto& row: matrixout){
        for (int j: row){
            cout << j << ' ';
        };
        cout << endl;
    };

}