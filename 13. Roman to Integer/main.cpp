#include <iostream>
#include <unordered_map>

using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        // Runtime: 12 ms
        // Memory Usage: 7.7 MB
        int result = 0;
        char prevDigit = 0;
        for (const char &c : s) {
            if (mRomanTable.find(c) != mRomanTable.end()) {
                int currentDigit = mRomanTable.at(c);
                if (currentDigit > prevDigit) {
                    if (prevDigit)
                    result-=prevDigit; // Undo
                    result+=currentDigit-prevDigit; // Add correct value
                } else {
                    result+=currentDigit;
                }
                prevDigit = currentDigit;
            }
            else {
                return -1;
            }
        }
        return result;
    }

private:
    const unordered_map<char, int>mRomanTable = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

};

int main() {
    Solution solution;
    std::cout << solution.romanToInt("MCMXCIV") << endl;
    return 0;
}
