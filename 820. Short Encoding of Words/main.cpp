#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        // Runtime: 1164 ms,      out of range
        // Memory Usage: 17.7 MB, 68%
        unordered_set<string> set;
        for (auto w : words) {
            w.append("#");
            bool isContains = false;
            for (const auto& s : set) {
                if (s.find(w) != std::string::npos) {
                    isContains = true;
                    break;
                }
                if (w.find(s) != std::string::npos) {
                    set.erase(s);
                    break;
                }
            }
            if (!isContains) {
                set.insert(w);
            }
        }

        int result = 0;
        for (const auto& s : set) {
            result+=s.length();
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<string> words( {"me", "time"} );
    cout << s.minimumLengthEncoding(words) << endl;
    return 0;
}

