#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        // Runtime: 556 ms,        98%
        // Memory Usage: 180.2 MB, 76%
        ListNode *constHead = head;
        ListNode *start = nullptr;
        ListNode *end = nullptr;
        int counter = 0;
        while (head != nullptr) {
            counter++;

            if (end != nullptr) {
                end = end->next;
            }

            if (counter == k) {
                start = head;
                end = constHead;
            }
            head = head->next;
        }

        swap(start->val, end->val);
        return constHead;
    }
};

int main()
{
    Solution s;
    ListNode a1(1);
    ListNode a2(2);
    ListNode a3(3);
    ListNode a4(4);
    ListNode a5(5);

    a1.next = &a2;
    a2.next = &a3;
    a3.next = &a4;
    a4.next = &a5;

    cout << s.swapNodes(&a1, 2)->val << endl;
    return 0;
}
