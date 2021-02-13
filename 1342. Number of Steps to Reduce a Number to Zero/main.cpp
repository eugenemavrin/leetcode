#include <iostream>

using namespace std;

class Solution {
public:
    int numberOfSteps (int num) {
        const int zero = 0;
        const int one = 1;
        int res = zero;
        while (num > zero) {
            if ((num & one ) == zero)
                num = num >> 1;
            else
                num-=one;
            res+=one;
        }
        return res;
    }
};

int main()
{
    Solution solution;
    cout << solution.numberOfSteps(14) << endl;
    return 0;
}
