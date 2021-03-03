#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        // Runtime: 0 ms
        // Memory Usage: 7 MB
        vector<string> result(n, "");
        int i = 0;
        while (i < n) {
            if ((i + 1) % 3 == 0) {
                result[i] = "Fizz";
            }
            if ((i + 1) % 5 == 0) {
                result[i].append("Buzz");
            }
            if (result[i] == "") {
                result[i] = to_string(i + 1);
            }

            i++;
        }

        return result;
    }
};

int main()
{
    Solution s;
    const auto result = s.fizzBuzz(16);
    for (const auto &r : result) {
        cout << r << endl;
    }
    return 0;
}
