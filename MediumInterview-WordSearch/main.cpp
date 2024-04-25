#include<vector>
#include<string>
using namespace std;


bool help(vector<vector<char>>& board, string word, size_t begin_i, size_t begin_j) {
    if (word.length() == 1) {
        return board[begin_i][begin_j] == word[0];
    }
    else {
        bool result = false;
        if (board[begin_i][begin_j] != word[0]) {
            return result;
        }
        board[begin_i][begin_j] = '0';
        if (begin_i > 0 && board[begin_i - 1][begin_j] != '0') {
            result = result | help(board, word.substr(1), begin_i - 1, begin_j);
        }
        if (begin_j > 0 && board[begin_i][begin_j - 1] != '0') {
            result = result | help(board, word.substr(1), begin_i, begin_j - 1);
        }
        if (begin_i < board.size() - 1 && board[begin_i + 1][begin_j] != '0') {
            result = result | help(board, word.substr(1), begin_i + 1, begin_j);
        }
        if (begin_j < board[0].size() - 1 && board[begin_i][begin_j + 1] != '0') {
            result = result | help(board, word.substr(1), begin_i, begin_j + 1);
        }
        board[begin_i][begin_j] = word[0]; // set to the initial state since using reference
        return result;
    }
}

bool exist(vector<vector<char>>& board, string word) {
    bool result = false;
    for (size_t i = 0; i < board.size(); i++) {
        for (size_t j = 0; j < board[0].size(); j++) {
            if (board[i][j] == word[0]) {
                result = result | help(board, word, i, j);
            }
        }
    }
    return result;
}
