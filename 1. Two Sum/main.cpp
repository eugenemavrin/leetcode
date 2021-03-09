#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Runtime: 4 ms,        97%
        // Memory Usage: 8.8 MB, 96%
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                if (nums[i] + nums[j] == target)
                    return {i, j};
            }
        }
        return {};
    }
};

int main()
{
    Solution s;
    vector<int> nums = { -3, 4, 3, 90 };
    const auto res = s.twoSum(nums, 0);
    cout << "Hello World!" << endl;
    return 0;
}

