#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1);
        for(int i = 0; i <= amount; i++)
            dp[i] = amount + 1;

        dp[0] = 0;
        for(int i = 1; i <= amount; i++) {
            for(int j = 0; j < coins.size(); j++) {
                if(i - coins[j] >= 0) {
                    dp[i] = min(dp[i-coins[j]] + 1, dp[i]);
                }
            }
        }

        return (dp[amount] == amount + 1) ? -1 : dp[amount];
    }
};

int main()
{
    Solution s;
    vector<int> coins = { 1, 2, 5 };
    cout << s.coinChange(coins, 11) << endl;
    return 0;
}

