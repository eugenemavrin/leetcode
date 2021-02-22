#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        // Runtime: 104 ms
        // Memory Usage: 22.7 MB
        string result = "";
        for (const string &word : d) {
            if (isContains(s, word)) {
                if (word.size() > result.size())
                    result = word;
                else if (word.size() == result.size())
                    result = word < result ? word : result;
            }
        }
        return result;
    }
private:
    bool isContains(string base, string word) {
        int baseSize = base.size();
        if (baseSize == 0)
            return false;

        int wordSize = word.size();
        if (wordSize == 0)
            return true;

        int offset = 0;
        int match = 0;
        for (int i = 0; i < baseSize; i++) {
            if (base.at(i) != word.at(i - offset))
                offset++;
            else
                match++;

            if (match == wordSize)
                return true;
        }
        return false;
    }
};

int main()
{
    Solution solution;
    vector<string> v = {"ba","aa","ca",""};
    cout << solution.findLongestWord("bacab", v) << endl;
    return 0;
}

