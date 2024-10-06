#include <iostream>
#include <vector>
using namespace std;


int minAtIdx(vector<vector<int>>& triangle, int idx) {
    if (triangle.size() == 1) {
        return triangle[0][0];
    }
    else {
        int last_row = triangle.size()-1;
        vector<vector<int>> upperTriangle(triangle.begin(), triangle.end()-1);
        if (idx == 0) {
            return triangle[last_row][0] + minAtIdx(upperTriangle, 0);
        }
        else if (idx == triangle[last_row].size()-1) {
            return triangle[last_row][idx] + minAtIdx(upperTriangle, idx-1);
        }
        else {
            int minLeft = minAtIdx(upperTriangle, idx-1);
            int minRight = minAtIdx(upperTriangle, idx);
            int min = minLeft;
            if (minLeft > minRight) {min = minRight;}
            return triangle[last_row][idx] + min;
        }
    }
}

int minimumTotal(vector<vector<int>>& triangle) {
    if (triangle.size() == 1) {
        return triangle[0][0];
    }
    vector<vector<int>> minPath(triangle.begin(), triangle.end());
    for (int i = 1; i < triangle.size(); i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            if (j == 0) {
                minPath[i][j] = triangle[i][j] + minPath[i-1][j];
            }
            else if (j == triangle[i].size()-1) {
                minPath[i][j] = triangle[i][j] + minPath[i-1][j-1];
            }
            else {
                int minAbove = minPath[i-1][j];
                if (minPath[i-1][j-1] < minAbove) {
                    minAbove = minPath[i-1][j-1];
                }
                minPath[i][j] = triangle[i][j] + minAbove;
            }
        }
    }
    int last_row = triangle.size()-1;
    int min = minPath[last_row][0];
    for (int i = 1; i < triangle[last_row].size(); i++) {
        int current = minPath[last_row][i];
        if (current < min) {
            min = current;
        }
    }
    return min;
}