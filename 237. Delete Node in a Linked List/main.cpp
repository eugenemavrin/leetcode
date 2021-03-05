#include <iostream>

using namespace std;

/**
* Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};


int main()
{
    ListNode *a4 = new ListNode(4);
    ListNode *a5 = new ListNode(5);
    ListNode *a1 = new ListNode(1);
    ListNode *a9 = new ListNode(9);
    a4->next = a5;
    a5->next = a1;
    a1->next = a9;

    Solution s;
    s.deleteNode(a5);
    cout << "Hello World!" << endl;
    return 0;
}

