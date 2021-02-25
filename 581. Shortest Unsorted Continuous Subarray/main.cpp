#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // Runtime: 24 ms
        // Memory Usage: 26.5 MB
        int len = nums.size();

        int firstIndex = len;
        int lastIndex = 0;

        // from min to max
        for (int i = 0; i < len - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                int j = i;
                while(j >= 0) {
                    if (nums[i + 1] >= nums[j])
                        break;
                    j--;
                }
                firstIndex = min(firstIndex, j + 1);
            }
        }

        // from max to min
        for (int i = len - 1; i >= 1; i--) {
            if (nums[i] < nums[i - 1]) {
                int j = i;
                while(j < len) {
                    if (nums[i - 1] <= nums[j])
                        break;
                    j++;
                }
                lastIndex = max(lastIndex, j - 1);
            }
        }

        // trim
        if (firstIndex < lastIndex) {
            nums.erase(nums.begin(), nums.begin() + firstIndex);
            nums.erase(nums.begin() + lastIndex - firstIndex + 1, nums.end());
            return nums.size();
        }
        return 0;
    }
};

int main() {
    Solution solution;
    vector<int> v = {1,3,2,3,3};
    std::cout << solution.findUnsortedSubarray(v) << endl;
    return 0;
}

