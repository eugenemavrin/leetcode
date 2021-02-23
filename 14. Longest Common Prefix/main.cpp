#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Runtime: 0 ms
        // Memory Usage: 9.1 MB
        int len = strs.size();
        if (len == 0)
            return "";

        string commonSuffix = strs.at(0);
        for (int i = 1; i < len; i++) {
            if (commonSuffix.size() > 0)
                cs(strs.at(i), commonSuffix);
            else
                break;
        }
        return commonSuffix;
    }

private:
    void cs(const string& word, string& suffix) { // cs - common suffix
        int i = 0;
        for (i = 0; i < min(word.size(), suffix.size()); i++) {
            if (word.at(i) != suffix.at(i)) {
                break;
            }
        }
        suffix.erase(i, suffix.size() - i);
    }
};

void printArray(const vector<char>& s);
int main()
{
    Solution solution;
    vector<string> strs = {"flower","flow","flight"};
    solution.longestCommonPrefix(strs);
    return 0;
}

