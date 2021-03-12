#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool hasAllCodes_(string s, int k) {
        // Runtime: 204 ms,       72%
        // Memory Usage: 69.1 MB, 17%
        int len = s.length() - k;
        vector<int>table(1 << k, 0);
        for (int i = 0; i <= len; i++) {
            table.at(std::stoi(s.substr(i, k), nullptr, 2))++;
        }

        for (const int t : table) {
            if (t == 0)
                return false;
        }
        return true;
    }

    bool hasAllCodes(string s, int k) {
        // Runtime: 232 ms,       68%
        // Memory Usage: 46.6 MB, 60%
        unordered_set<int>table;
        int len = s.length() - k;
        for (int i = 0; i <= len; i++) {
            table.insert(std::stoi(s.substr(i, k), nullptr, 2));
            if (table.size() == (1 << k))
                break;
        }

        return table.size() == (1 << k);
    }
};

int main()
{
    Solution s;
    cout << s.hasAllCodes("0110", 2) << endl;
    return 0;
}
