#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        // Runtime: 8 ms,        89%
        // Memory Usage: 5.9 MB, 81%
        if (n == 1)
            return true;

        const int three = 3;
        if (n % three != 0 && n > 1)
            return false;

        n = n / three;
        int res = 1;
        while (res < n) {
            res *= three;
        }
        return res == n;
    }
};

int main()
{
    Solution s;
    cout << s.isPowerOfThree(1) << endl;
    return 0;
}
