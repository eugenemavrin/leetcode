#include <iostream>
#include <unordered_map>

using namespace std;

namespace  {
unordered_map<int, string> Arabic2Roman {
    {1,    "I"},
    {5,    "V"},
    {10,   "X"},
    {50,   "L"},
    {100,  "C"},
    {500,  "D"},
    {1000, "M"},
};
};

class Solution {
public:
    string intToRoman(int num) {
        // Runtime: 4 ms,        88%
        // Memory Usage: 6.2 MB, 63%
        if (num > 3999 || num < 0)
            return "";

        string roman;
        int divider = 10;
        int pow = 1;
        while(num > 0) {
            roman = digitToRoman(num % divider, pow) + roman;
            num /= divider;
            pow *= divider;
        }

        return  roman;
    }
private:
    string digitToRoman(int num, int pow) {
        string roman;
        if (num <= 3) {
            for (int i = 0; i < num; i++) {
                roman.append(Arabic2Roman.at(pow));
            }
        } else if (num == 4) {
            roman.append(Arabic2Roman.at(pow));
            roman.append(Arabic2Roman.at(pow * 5));
        } else if (num <= 8){
            roman.append(Arabic2Roman.at(pow * 5));
            num -= 5;
            for (int i = 0; i < num; i++) {
                roman.append(Arabic2Roman.at(pow));
            }
        } else {
            roman.append(Arabic2Roman.at(pow));
            roman.append(Arabic2Roman.at(pow * 10));
        }

        return roman;
    }
};

int main()
{
    Solution s;
    for (int i = 1; i < 4000; i++) {
        cout << i << " = " << s.intToRoman(i) << endl;
    }

    return 0;
}

