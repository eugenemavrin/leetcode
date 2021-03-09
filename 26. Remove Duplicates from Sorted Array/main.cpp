#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int removeDuplicates_(vector<int>& nums) {
        // Runtime: 76 ms,        21%
        // Memory Usage: 14.2 MB,  8%
        if (nums.size() == 0)
            return 0;

        vector<int> indexes;
        int prevIndex = 0;
        int prevValue = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == prevValue) {
                if (i - prevIndex == 1) {
                    indexes.push_back(i);
                    indexes.push_back(1);
                } else {
                    indexes.back()++;
                }
            } else {
                prevIndex = i;
                prevValue = nums[i];
            }
        }

        if (indexes.size() == 0)
            return nums.size();

        for (int i = indexes.size() - 2; i >= 0; i -= 2) {
            nums.erase(nums.begin() + indexes[i], nums.begin() + indexes[i] + indexes[i + 1]);
        }

        return nums.size();
    }

    int removeDuplicates__(vector<int>& nums) {
        // Runtime: 12 ms,        74%
        // Memory Usage: 15.5 MB,  8%
        set<int> res(nums.begin(), nums.end());
        nums = vector<int>(res.begin(), res.end());
        return res.size();
    }

    int removeDuplicates(vector<int>& nums) {
        // Runtime: 68 ms,        21%
        // Memory Usage: 13.7 MB, 77%
        int eraseStart = nums.size() - 1;
        int eraseEnd = nums.size() - 1;
        for (int i = nums.size() - 2; i >=0; i--) {
            eraseStart = i;
            if (nums[i] != nums[i + 1]) {
                nums.erase(nums.begin() + eraseStart + 1, nums.begin() + eraseEnd);
                eraseEnd = i;
            }
        }

        if (eraseStart != eraseEnd) {
            nums.erase(nums.begin() + eraseStart, nums.begin() + eraseEnd);
        }

        return nums.size();
    }
};

int main()
{
    Solution s;
    vector<int> nums {0,1,1,1,2,2,3,3,4};
    cout << s.removeDuplicates(nums) << endl;
    return 0;
}

