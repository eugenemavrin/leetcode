#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if (root == nullptr)
            return nullptr;

        int sum = 0;
        recursive(root, sum);
        return root;
    }
private:
    void recursive(TreeNode *node, int& sum) {
        if (node->right != nullptr)
            recursive(node->right, sum);

        node->val += sum;
        sum=node->val;

        if (node->left != nullptr)
            recursive(node->left, sum);
    }
};

int main()
{
    TreeNode node4(4);
    TreeNode node1(1);
    TreeNode node0(0);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node6(6);
    TreeNode node5(5);
    TreeNode node7(7);
    TreeNode node8(8);

    node4.left = &node1;
    node4.right = &node6;

    node1.left = &node0;
    node1.right = &node2;

    node2.right = &node3;

    node6.left = &node5;
    node6.right = &node7;

    node7.right = &node8;

    Solution solution;
    solution.convertBST(&node4);
    return 0;
}
