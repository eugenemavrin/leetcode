#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution(vector<int>& nums) {
        mVector = nums;
        mLen = mVector.size();
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return mVector;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> shuffleVector = mVector;
        for (int i = 0; i < mLen; i++) {
            int i1 = random() % mLen;
            int i2 = random() % mLen;
            while (i1 == i2) {
                i1 = random() % mLen;
                i2 = random() % mLen;
            }
            swap(shuffleVector[random() % mLen], shuffleVector[random() % mLen]);
        }
        return shuffleVector;
    }
private:
    vector<int> mVector;
    int mLen;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

int main()
{
    vector<int>test = {1, 2, 3};
    Solution s(test);
    auto x = s.reset();
    auto y = s.shuffle();
    auto a = s.reset();
    auto b = s.shuffle();
    cout << "Hello World!" << endl;
    return 0;
}
