#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class point {
    public:
        int i;
        int j;
        point(int pi, int pj) : i(pi), j(pj) {};
};


int numIslands(vector<vector<char>>& grid) {
    int count = 0;
    int numCheck = 0;
    int totalGrid = grid.size() * grid[0].size();
    vector<vector<bool>> gridCheck(grid.size(), vector<bool>(grid[0].size(), false));
    while (numCheck < totalGrid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1' && !gridCheck[i][j]) {
                    count++;
                    queue<point> ptQueue;
                    point currPoint(i, j);
                    ptQueue.push(currPoint);
                    gridCheck[i][j] = true;
                    numCheck++;
                    while (!ptQueue.empty()) {
                        point temp = ptQueue.front();
                        ptQueue.pop();
                        if (temp.i > 0 && !gridCheck[temp.i-1][temp.j] && grid[temp.i-1][temp.j] == '1') {
                            point up(temp.i-1, temp.j);
                            ptQueue.push(up);
                            gridCheck[temp.i-1][temp.j] = true;
                            numCheck++;
                        }
                        if (temp.j > 0 && !gridCheck[temp.i][temp.j-1] && grid[temp.i][temp.j-1] == '1') {
                            point left(temp.i, temp.j-1);
                            ptQueue.push(left);
                            gridCheck[temp.i][temp.j-1] = true;
                            numCheck++;
                        }
                        if (temp.i < grid.size()-1 && !gridCheck[temp.i+1][temp.j] && grid[temp.i+1][temp.j] == '1') {
                            point down(temp.i+1, temp.j);
                            ptQueue.push(down);
                            gridCheck[temp.i+1][temp.j] = true;
                            numCheck++;
                        }
                        if (temp.j < grid[0].size()-1 && !gridCheck[temp.i][temp.j+1] && grid[temp.i][temp.j+1] == '1') {
                            point right(temp.i, temp.j+1);
                            ptQueue.push(right);
                            gridCheck[temp.i][temp.j+1] = true;
                            numCheck++;
                        }
                    }
                }
                if (grid[i][j] == '0' && !gridCheck[i][j]) {
                    gridCheck[i][j] = true;
                    numCheck++;
                }
            }
        }
    }
    return count;
}


int main() {
    vector<vector<char>> grid;
    grid.push_back({'1', '1', '1', '1', '0'});
    grid.push_back({'1', '1', '0', '1', '0'});
    grid.push_back({'1', '1', '0', '0', '0'});
    grid.push_back({'1', '1', '0', '0', '0'});
    cout << numIslands(grid) << endl;
    return 0;
}
