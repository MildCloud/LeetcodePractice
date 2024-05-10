#include <vector>
using namespace std;


bool searchMatrix(vector<vector<int>>& matrix, int target) {
    for (size_t i = 0; i < matrix.size(); i++) {
        if (matrix[i][0] > target) {
            break;
        }
        if (matrix[i][0] <= target && matrix[i][matrix[0].size()-1] >= target) {
            for (size_t j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == target) {
                    return true;
                }
                if (matrix[i][j] > target) {
                    break;
                }
            }
        }
    }
    return false;
}


int main() {
    return 0;
}
