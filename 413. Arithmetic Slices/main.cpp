#include <iostream>
#include <vector>

using namespace std;

namespace C {
int minSliceLen = 3;
}

class Solution {
public:
    int numberOfArithmeticSlicesLong(vector<int>& A) {
        // Runtime: 164 ms
        // Memory Usage: 7.2 MB
        int vectorLen = A.size();
        if (vectorLen < C::minSliceLen)
            return 0;

        int result = 0;
        bool flag = false;
        for (int l = C::minSliceLen; l <= vectorLen; l++) { // l -- Array slice len
            for (int f = 0; f <= vectorLen - l; f++) {      // f -- index of first element of current slice
                int diff = A[f] - A[f+1];
                for (int i = f + 1; i < f + l - 1; i++) {   // i -- current slice iterator
                    flag = diff == A[i] - A[i+1];
                    if (!flag)
                        break;
                }
                if (flag) {
                    result++;
                    flag = false;
                }
            }
        }
        return result;
    }
    
    int numberOfArithmeticSlices(vector<int>& A) {
        // Runtime: 4 ms
        // Memory Usage: 7.2 MB
        int vectorLen = A.size();
        if (vectorLen < C::minSliceLen)
            return 0;

        int result = 0;
        int winningSession = 0;
        for (int i = 1; i < vectorLen - 1; i++) {
            if (A[i-1] - A[i] == A[i] - A[i+1]) {
                winningSession++;
                result+=winningSession;
            } else {
                winningSession = 0;
            }
        }
        return result;
    }
};
int main() {
    Solution solution;
    vector<int> A = {1, 2, 3, 4, 4, 4, 3, 2, 1, 0};
    std::cout << solution.numberOfArithmeticSlicesLong(A) << endl;
    std::cout << solution.numberOfArithmeticSlices(A) << endl;
    return 0;
}
