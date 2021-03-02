#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        // Runtime: 40 ms
        // Memory Usage: 21.4 MB
        sort(nums.begin(), nums.end(), [](const int&a, const int&b){return a < b;});
        int repeated;
        int missed = -1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i-1] == 0) {
                repeated = nums[i];
            }
            if (nums[i] - nums[i-1] > 1) {
                missed = nums[i] - 1;
            }
        }

        if (missed == -1) {
            if (nums[0] != 1)
                missed = 1;
            else
                missed = nums.back() + 1;
        }

        return {repeated, missed};
    };
};

int main()
{
    Solution s;
    vector<int> test = {1, 1};
    vector<int> res = s.findErrorNums(test);
    return 0;
}
