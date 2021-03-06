#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        // Runtime: 836 ms, out of range
        // Memory Usage: 5.7 MB, 99%
        int result = 0;
        for (int i = 2; i < n; i++) {
            if (!isPrime(i)) {
                result++;
            }
        }

        return result;
    }

private:
    bool isPrime(int n) {
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0)
                return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
    cout << s.countPrimes(10) << endl;
    return 0;
}

