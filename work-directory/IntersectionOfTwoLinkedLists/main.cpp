#include <iostream>
#include <set>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    ListNode(int x) : val(x), next(NULL) {}
    int val;
    ListNode *next;
};

class Solution {
public:
    ListNode *getIntersectionNode_(ListNode *headA, ListNode *headB) {
        // Runtime: 932 ms,       out of range
        // Memory Usage: 14.4 MB, 95%
        ListNode *nodeA = headA;
        ListNode *nodeB = headB;
        while (nodeA != nullptr) {
            while (nodeB != nullptr) {
                if(nodeA == nodeB) {
                    return nodeB;
                }
                nodeB = nodeB->next;
            }
            nodeA = nodeA->next;
            nodeB = headB;
        }

        return nullptr;
    }

    ListNode *getIntersectionNode__(ListNode *headA, ListNode *headB) {
        // Runtime: 72 ms,      18%
        // Memory Usage: 18 MB,  8%
        ListNode *nodeA = headA;
        ListNode *nodeB = headB;
        set<ListNode *> a;
        while (nodeA != nullptr) {
            a.insert(nodeA);
            nodeA = nodeA->next;
        }
        while (nodeB != nullptr) {
            if(a.count(nodeB) > 0)
                return nodeB;
            nodeB = nodeB->next;
        }

        return nullptr;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Runtime: 48 ms,        40%
        // Memory Usage: 14.6 MB, 68%
        int aLen = listLen(headA);
        int bLen = listLen(headB);

        ListNode *nodeA = headA;
        ListNode *nodeB = headB;
        int commonLen;
        if (aLen > bLen) {
            commonLen = bLen;
            for (int i = 0; i < aLen - bLen; i++) {
                nodeA = nodeA->next;
            }
        } else {
            commonLen = aLen;
            for (int i = 0; i < bLen - aLen; i++) {
                nodeB = nodeB->next;
            }
        }

        for (int i = 0; i < commonLen; i++ ) {
            if (nodeA == nodeB) {
                return nodeA;
            }
            nodeA = nodeA->next;
            nodeB = nodeB->next;
        }

        return nullptr;
    }
private:
    int listLen(ListNode *head) {
        ListNode *node = head;
        int len = 0;
        while (node != nullptr) {
            len++;
            node = node->next;
        }

        return len;
    }
};

int main()
{
    /** Testcase #1
     *
     *           A: (4) --> (1)
     *               1       2  \
     *                        C:  --> (8) --> (4) --> (5)
     *                          /      1       2       3
     *   B: (5) --> (6) --> (1)
     *       1       2       3
     *
     */

    ListNode a1(4);
    ListNode a2(1);
    ListNode b1(5);
    ListNode b2(6);
    ListNode b3(1);
    ListNode c1(8);
    ListNode c2(4);
    ListNode c3(5);

    a1.next = &a2;
    a2.next = &c1;

    b1.next = &b2;
    b2.next = &b3;
    b3.next = &c1;

    c1.next = &c2;
    c2.next = &c3;

    Solution s;
    cout << s.getIntersectionNode(&a1, &b1)->val << endl;

    return 0;
}
