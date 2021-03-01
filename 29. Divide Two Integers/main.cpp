#include <iostream>

using namespace std;

namespace C {
int MAX = 2147483647;
int MIN = -2147483648;
}

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Runtime: 1784 ms
        // Memory Usage: 5.9 MB
        int result = 0;
        int negDividend = dividend > 0 ? -dividend : dividend;
        int negDivisor =  divisor > 0 ? -divisor : divisor;
        if (negDivisor != -1) {
            while (negDividend <= negDivisor) {
                negDividend-=negDivisor;
                result--;
            }
        } else {
            result = negDividend;
        }

        if ((dividend < 0 && divisor > 0) || (dividend >= 0 && divisor < 0))
            return result;

        if (result <= -C::MAX)
            return C::MAX;

        return -result;
    }
};

int main()
{
    Solution s;
    cout << s.divide(-2147483648, 1) << endl;
    return 0;
}

