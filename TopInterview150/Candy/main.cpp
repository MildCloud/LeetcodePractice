#include <iostream>
#include <vector>
using namespace std;


int candy(vector<int>& ratings) {
    vector<int> candyNums(ratings.size(), 1);
    int totalCandy = 0;
    for (int i = 1; i < ratings.size(); i++) {
        if (ratings[i-1] < ratings[i]) {
            candyNums[i] = candyNums[i-1] + 1;
        }
        else if (ratings[i-1] > ratings[i]) {
            if (candyNums[i] == candyNums[i-1]) {
                for (int j = i-1; j > -1; j--) {
                    if (j == 0 || ratings[j-1] <= ratings[j]) {
                        if (candyNums[j] == candyNums[j+1]) {
                            candyNums[j]++;
                        }
                        break;
                    }
                    if (candyNums[j] == candyNums[j+1]) {
                        candyNums[j]++;
                    }
                }
            }
        }
    }
    for (int i = 0; i < candyNums.size(); i++) {
        totalCandy += candyNums[i];
    }
    return totalCandy;
}