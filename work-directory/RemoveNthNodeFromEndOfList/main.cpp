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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Runtime: 0 ms,         100%
        // Memory Usage: 10.5 MB, 99%

        ListNode *node = head;
        ListNode *nextToRemove = nullptr;

        int counter = 0;
        while (node->next != nullptr) {
            if (nextToRemove != nullptr)
                nextToRemove = nextToRemove->next;

            if (counter == n - 1)
                nextToRemove = head;

            node = node->next;
            counter++;
        }
        counter++; // 'cause checked only node->next. It means that the current node value != nullptr;

        if (n > counter) // no changes if n greather than a node conuter
            return head;

        if (n == counter) {  // erase head node
            head = head->next;
        } else if (n == 1) { // erase tail node
            nextToRemove->next = nullptr;
        } else {             // erase mid node
            nextToRemove->next->val = nextToRemove->next->next->val;
            nextToRemove->next->next = nextToRemove->next->next->next;
        }

        return head;
    }
};

int main()
{
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);
    ListNode n5(5);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    Solution s;
    cout << s.removeNthFromEnd(&n4, 2)->val << endl;
    return 0;
}
