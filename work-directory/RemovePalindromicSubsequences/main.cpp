#include <iostream>

using namespace std;

class Solution {
public:
    int removePalindromeSub(string s) {
        // Runtime: 0 ms,        100%
        // Memory Usage: 6.1 MB, 91%
        if(s.size() == 0)
            return 0;

        return isPalindrome(s) ? 1 : 2;
    }
private:
    bool isPalindrome(const string& s) {
        int len = s.size();
        for (int i = 0; i < len / 2; i++) {
            if (s[i] != s[len - 1 - i])
                return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout << s.removePalindromeSub("ababa") << endl;
    return 0;
}
