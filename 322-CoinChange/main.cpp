#include <iostream>
#include <vector>
#include <limits>
using namespace std;


int coinChange (vector<int> & coins, int amount) {
    vector<vector<int>> memo(amount + 1, vector<int>(coins.size(), 0));
    for (size_t i = 1; i <= (size_t)amount; i++) {
        for (size_t j = 0; j < coins.size(); j++) {
            if (i >= (size_t)coins[j]) {
                bool canMade = false;
                int minChange = numeric_limits<int>::max();
                size_t minCol = 0;
                for (size_t k = 0; k < coins.size(); k++) {
                    if (memo[i - coins[j]][k] < minChange && memo[i - coins[j]][k] != -1) {
                        minChange = memo[i - coins[j]][k];
                        minCol = k;
                        canMade = true;
                    }
                }
                if (canMade) {
                    memo[i][j] = memo[i - coins[j]][minCol] + 1;
                }
                else {
                    memo[i][j] = -1;
                }
            }
            else {
                memo[i][j] = -1;
            }
        }
    }
    bool canMade = false;
    int minChange = numeric_limits<int>::max();
    for (size_t i = 0; i < coins.size(); i++) {
        if (memo[amount][i] != -1 && memo[amount][i] < minChange) {
            minChange = memo[amount][i];
            canMade = true;
        }
    }
    if (canMade) {
        return minChange;
    }
    else {
        return -1;
    }
}


int main () {
    vector<int> coins = {3, 5};
    int amount = 0;
    cout << coinChange(coins, amount) << endl;
    return 0;
}
