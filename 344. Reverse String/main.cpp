#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        // Runtime: 24 ms
        // Memory Usage: 23.1 MB
        int len = s.size();
        for (int i = 0; i < len / 2; i++) {
            char buffer = s.at(i);
            s.at(i) = s.at(len - i - 1);
            s.at(len - i - 1) = buffer;
        }
    }
};

void printArray(const vector<char>& s);
int main()
{
    Solution solution;
    vector<char> s = {'H','e','y','l','o', '!'};
    printArray(s);
    solution.reverseString(s);
    printArray(s);
    return 0;
}

void printArray(const vector<char>& s) {
    for (const auto& c : s) {
        cout << c;
    }
    cout << endl;
}

