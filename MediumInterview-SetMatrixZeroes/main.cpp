#include <iostream>
#include <vector>
using namespace std;


void setZeroes(vector<vector<int>> & matrix) {
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] != 0) {
                matrix[i][j] = 1;
            }
        }
    }
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] == 0) {
                for (size_t k = 0; k < matrix[0].size(); k++) {
                    if (matrix[i][k] == 1) {
                        matrix[i][k] = -1;
                    }
                }
                for (size_t k = 0; k < matrix.size(); k++) {
                    if (matrix[k][j] == 1) {
                        matrix[k][j] = -1;
                    }
                }
            }
        }
    }
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = 0;
            }
        }
    }
}


int main () {
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    vector<vector<int>> matrix2 = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    setZeroes(matrix);
    setZeroes(matrix2);
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    for (size_t i = 0; i < matrix2.size(); i++) {
        for (size_t j = 0; j < matrix2[0].size(); j++) {
            cout << matrix2[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
