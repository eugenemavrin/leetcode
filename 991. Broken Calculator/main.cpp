#include <iostream>

using namespace std;
class Solution {
public:
    int brokenCalc(int X, int Y) {
        // Runtime: 0 ms
        // Memory Usage: 5.9 MB
        int result = 0;
        while (Y > X) {
            if (Y % 2 == 1)
                Y++;
            else
                Y /= 2;
            result++;
        }
        return result + X-Y;
    }
};

int main() {
    Solution solution;
    std::cout << solution.brokenCalc(2, 3) << endl; // brokenCalc(1, 1000000000) ret 39
    return 0;
}
