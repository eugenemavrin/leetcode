#include <iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        // Runtime: 0 ms
        // Memory Usage: 5.9 MB
        int res = 0;
        while (n > 0) {
            res += n % 2;
            n /= 2;
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout << s.hammingWeight(15) << endl;
    return 0;
}

