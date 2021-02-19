#include <iostream>
#include <vector>

using namespace std;

namespace {
const char OBR = '('; // Open Bracket
const char CBR = ')'; // Close Bracket
}

class Stack {
public:
    Stack() = default;
    void push(char c, int i) {
        mStack.push_back(pair<char, int>(c, i));
    }
    pair<char,int> pop() {
        auto back = mStack.back();
        mStack.pop_back();
        return back;
    }
    pair<char, int> peek() {
        return mStack.back();
    }
    bool isEmpty() {
        return mStack.size() == 0;
    }
private:
    vector<pair<char, int>> mStack;
};

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // Runtime: 36 ms
        // Memory Usage: 10 MB
        int len = s.length();
        if (len == 0)
            return s;
        Stack stack;
        for (int i = 0; i < len; i++) {
            const char c = s[i];
            if (c == OBR) {
                stack.push(c, i);
            }
            if (c == CBR) {
                if (!stack.isEmpty() && stack.peek().first == OBR)
                    stack.pop();
                else
                    stack.push(c, i);
            }
        }

        while(!stack.isEmpty())
            s.erase(stack.pop().second, 1);

        return s;
    }
};

int main() {
    Solution solution;
    std::cout << solution.minRemoveToMakeValid("asb") << endl;
    return 0;
}
