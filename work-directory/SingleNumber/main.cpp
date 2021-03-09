#include <iostream>
#include <vector>
#include <unordered_set>
#include <numeric>

using namespace std;

class Solution {
public:
    int singleNumber_(vector<int>& nums) {
        // Runtime: 20 ms,        81%
        // Memory Usage: 20.2 MB, 17%
        unordered_set<int>set(nums.begin(), nums.end());
        int sumSet = accumulate(set.begin(), set.end(), 0);
        int sumVector = accumulate(nums.begin(), nums.end(), 0);
        return sumSet * 2 - sumVector;
    }

    int singleNumber(vector<int>& nums) {
        // Runtime: 12 ms,        98%
        // Memory Usage: 16.8 MB, 89%
        int result = 0;
        for (int n : nums)
            result ^= n;

        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {4, 2, 1, 2, 1};
    cout << s.singleNumber(nums) << endl;
    return 0;
}
