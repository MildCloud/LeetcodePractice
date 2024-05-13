#include <vector>
#include <iostream>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<vector<int>> numberTable(coins.size(), vector<int>(amount+1, -1));
    for (int i = 0; i < coins.size(); i++) {
        if (i == 0) {
            for (int j = 0; j < amount+1; j++) {
                if (j % coins[i] == 0) {
                    numberTable[i][j] = j / coins[i];
                }
            }
        }
        else {
            for (int j = 0; j < amount+1; j++) {
                int currMin = numberTable[i-1][j];
                for (int k = j; k >= 0; k -= coins[i]){
                    if (numberTable[i][k] != -1 && (numberTable[i][k] + (j-k)/coins[i] < currMin || currMin == -1)) {
                        currMin = numberTable[i][k] + (j-k)/coins[i];
                    }
                }
                numberTable[i][j] = currMin;
            }
        }
    }
    for (size_t i = 0; i < numberTable.size(); i++) {
        for (size_t j = 0; j < numberTable[0].size(); j++) {
            cout << numberTable[i][j] << " ";
        }
        cout << endl;
    }
    return numberTable[coins.size()-1][amount];
}

int main() {
    vector<int> v = {2,5,10,1};
    cout << coinChange(v, 27) << endl;
    return 0;
}
