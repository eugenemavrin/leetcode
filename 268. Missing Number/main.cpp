#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // Runtime: 16 ms
        // Memory Usage: 17.9 MB
        int reqSum = (nums.size() * (nums.size() + 1)) / 2;
        int sum = 0;

        bool containsZero = false;
        for (const auto &n : nums) {
            sum+=n;
            if (n == 0) {
                containsZero = true;
            }
        }

        int result = reqSum - sum;
        if (result == 0)
            result = containsZero ? nums.size() + 1 : 0;

        return result;
    }
};

int main()
{
    Solution s;
    vector<int> test ={1, 2};
    cout << s.missingNumber(test) << endl;
    return 0;
}

