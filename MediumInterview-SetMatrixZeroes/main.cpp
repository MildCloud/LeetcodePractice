#include <iostream>
#include <vector>
using namespace std;


// void setZeroes(vector<vector<int>> & matrix) {
//     for (size_t i = 0; i < matrix.size(); i++) {
//         for (size_t j = 0; j < matrix[0].size(); j++) {
//             if (matrix[i][j] != 0) {
//                 matrix[i][j] = 1;
//             }
//         }
//     }
//     for (size_t i = 0; i < matrix.size(); i++) {
//         for (size_t j = 0; j < matrix[0].size(); j++) {
//             if (matrix[i][j] == 0) {
//                 for (size_t k = 0; k < matrix[0].size(); k++) {
//                     if (matrix[i][k] == 1) {
//                         matrix[i][k] = -1;
//                     }
//                 }
//                 for (size_t k = 0; k < matrix.size(); k++) {
//                     if (matrix[k][j] == 1) {
//                         matrix[k][j] = -1;
//                     }
//                 }
//             }
//         }
//     }
//     for (size_t i = 0; i < matrix.size(); i++) {
//         for (size_t j = 0; j < matrix[0].size(); j++) {
//             if (matrix[i][j] == -1) {
//                 matrix[i][j] = 0;
//             }
//         }
//     }
// }


void setZeroes(vector<vector<int>> & matrix) {
    bool R1 = false, C1 = false;
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
                if (i == 0) {
                    R1 = true;
                }
                if (j == 0) {
                    C1 = true;
                }
            }
        }
    }
    for (size_t i = 1; i < matrix.size(); i++) {
        if (matrix[i][0] == 0) {
            for (size_t j = 0; j < matrix[0].size(); j++) {
                matrix[i][j] = 0;
            }
        }
    }
    for (size_t j = 1; j < matrix[0].size(); j++) {
        if (matrix[0][j] == 0) {
            for (size_t i = 0; i < matrix.size(); i++) {
                matrix[i][j] = 0;
            }
        }
    }
    if (C1) {
        for (size_t i = 1; i < matrix.size(); i++) {
            matrix[i][0] = 0;
        }
    }
    if (R1) {
        for (size_t j = 1; j < matrix[0].size(); j++) {
            matrix[0][j] = 0;
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
