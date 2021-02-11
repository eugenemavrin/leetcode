#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s == t)
            return true;

        if (s.size() != t.size())
            return false;

        //Runtime: 668 ms
        //Memory Usage: 7.3 MB

        //With & for consts
        //Runtime: 672 ms
        //Memory Usage: 7.1 MB

        /*
        for (const auto &c : s) {
            const auto &pos = t.find(c);
            if (pos != std::string::npos)
                t.erase(pos, 1);
            else
                return false;
        }
        return t.size() == 0;
        */
        //Runtime: 12 ms
        //Memory Usage: 7.4 MB
        unordered_map<char, int>map;
        for (const auto c : s) {
            if (map.find(c) == map.end()) {
                map.insert(pair<char, int>(c, 1));
            } else {
                map.at(c)++;
            }
        }
        for (const auto c : t) {
            if (map.find(c) == map.end())
                return false;

            map.at(c)--;
            if (map.at(c) == 0) {
                map.erase(c);
            }
        }
        return map.size() == 0;
    }
};

int main()
{
    Solution solution;
    std::cout << solution.isAnagram("lol", "oll");
    return 0;
}