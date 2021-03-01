#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        // Runtime: 204 ms
        // Memory Usage: 102.3 MB
        unordered_set<int> uniqueCandyType;
        const int half = candyType.size() / 2;
        for (const int &candy : candyType) {
            if (uniqueCandyType.size() < half)
                uniqueCandyType.insert(candy);
            else
                return half;
        }
        return uniqueCandyType.size();
    }
};


int main()
{
    Solution s;
    vector<int> test = { 6,6,6,6 };
    cout << s.distributeCandies(test) << endl;
    return 0;
}

