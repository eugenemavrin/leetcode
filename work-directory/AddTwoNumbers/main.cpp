#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Runtime: 28 ms,        77%
        // Memory Usage: 71.2 MB, 67%
        ListNode head;
        ListNode *node = new ListNode();
        head.next = node;
        int buffer = 0;
        while (l1 != nullptr || l2 != nullptr) {
            int val = buffer;
            if (l1 != nullptr) {
                val += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                val += l2->val;
                l2 = l2->next;
            }

            if (val > 9) {
                buffer = 1;
                val -= 10;
            } else {
                buffer = 0;
            }
            ListNode *newNode = new ListNode(val);
            node->next = newNode;
            node = node->next;
        }

        if (buffer > 0) {
            ListNode *newNode = new ListNode(buffer);
            node->next = newNode;
        }

        return head.next->next;
    }
};

int main()
{

    ListNode a1(9);
    ListNode a2(9);
    ListNode a3(9);
    ListNode a4(9);
    a1.next = &a2;
    a2.next = &a3;
    a3.next = &a4;

    ListNode b1(9);
    ListNode b2(9);
    ListNode b3(9);
    ListNode b4(9);
    ListNode b5(9);
    ListNode b6(9);
    ListNode b7(9);
    ListNode b8(9);
    ListNode b9(9);
    b1.next = &b2;
    b2.next = &b3;
    b3.next = &b4;
    b4.next = &b5;
    b5.next = &b6;
    b6.next = &b7;
    b7.next = &b8;
    b8.next = &b9;

    Solution s;
    ListNode *res = s.addTwoNumbers(&a1, &b1);

    cout << "result:" << endl;
    while (res != nullptr) {
        cout << res->val;
        res = res->next;
    }
    cout << endl;

    cout << "Hello World!" << endl;
    return 0;
}
