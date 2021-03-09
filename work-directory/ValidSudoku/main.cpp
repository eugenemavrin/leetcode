#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

namespace {
int BS = 9; //Board Size;
}

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Runtime: 28 ms,        60%
        // Memory Usage: 20.7 MB, 22%
        bool result = true;
        for (int i = 0; i < BS; i++) {
            result &= checkRow(board, i);
            result &= checkCol(board, i);
            if (!result)
                break;
        }

        for (int i = 0; i < BS; i +=3) {
            for (int j = 0; j < BS; j +=3) {
                result &= check3x3(board, i, j);
                if (!result)
                    break;
            }
        }

        return result;
    }
private:
    bool check3x3(const vector<vector<char>>& board, int i, int j) {
        unordered_set<char> set;
        for (int x = i; x < i + 3; x++) {
            for (int y = j; y < j + 3; y++) {
                char c = board[x][y];
                if (c != '.') {
                    if (set.count(c) > 0)
                        return false;
                    set.insert(c);
                }
            }
        }
        return true;
    }

    bool checkRow(const vector<vector<char>>& board, int i) {
        unordered_set<char> set;
        for (int j = 0; j < BS; j++) {
            char c = board[i][j];
            if (c != '.') {
                if (set.count(c) > 0)
                    return false;
                set.insert(c);
            }
        }
        return true;
    }
    bool checkCol(const vector<vector<char>>& board, int i) {
        unordered_set<char> set;
        for (int j = 0; j < BS; j++) {
            char c = board[j][i];
            if (c != '.') {
                if (set.count(c) > 0)
                    return false;
                set.insert(c);
            }
        }
        return true;
    }
};

int main()
{
    vector<vector<char>> validSudoku = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    vector<vector<char>> invalidSudoku = {
        {'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution s;
    cout << s.isValidSudoku(validSudoku) << endl
         << s.isValidSudoku(invalidSudoku) << endl;
    return 0;
}
