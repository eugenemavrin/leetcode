#include <iostream>
#include <unordered_map>

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node();

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;

        std::unordered_map<Node*, Node*> nodeMap;
        nodeMap.insert(std::pair<Node*, Node*>(head, new Node(head->val)));
        Node* nextNode = head->next;
        while (nextNode != nullptr) {
            nodeMap.insert(std::pair<Node*, Node*>(nextNode, new Node(nextNode->val)));
            nextNode = nextNode->next;
        }
        delete nextNode;
        for (auto &node : nodeMap) {
            if (node.first->next != nullptr)
                node.second->next = nodeMap.at(node.first->next);
            if (node.first->random != nullptr)
                node.second->random = nodeMap.at(node.first->random);
        }

        return nodeMap.at(head);
    }
};

int main() {

    Node n0(7);
    Node n1(13);
    Node n2(11);
    Node n3(10);
    Node n4(1);
    n0.next = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = nullptr;
    n0.random = nullptr;
    n1.random = &n0;
    n2.random = &n4;
    n3.random = &n2;
    n4.random = &n0;

    Solution solution;
    Node* node = solution.copyRandomList(&n0);
    std::cout << node->val;
    return 0;
}