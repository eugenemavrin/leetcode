#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
class Solution {
public:
    int maxDepth(TreeNode* root) {
        // Runtime: 8 ms
        // Memory Usage: 19.2 MB
        int depth = 0;
        recursive(root, depth);
        return depth;
    }
private:
    void recursive(TreeNode* node, int &depth) {
        if (node == nullptr)
            return;

        depth++;
        if (node->left == nullptr && node->right == nullptr)
            return;

        int left = 0;
        if (node->left != nullptr)
            recursive(node->left, left);

        int right = 0;
        if (node->right != nullptr)
            recursive(node->right, right);

        depth += max(left, right);
    }
};
*/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        // Runtime: 8 ms
        //Memory Usage: 18.9 MB
        if (root == nullptr)
            return 0;

        return max(maxDepth(root->right), maxDepth(root->left)) + 1;
    }
};

int main() {
    /**
     * Main testcase:
     *
     *      3
     *     / \
     *    9  20
     *      /  \
     *     15   7
     *
     * Max depth: 3
     */

    TreeNode n3 = TreeNode(3);
    TreeNode n9 = TreeNode(9);
    TreeNode n20 = TreeNode(20);
    TreeNode n15 = TreeNode(15);
    TreeNode n7 = TreeNode(7);

    n3.left = &n9;
    n3.right = &n20;
    n20.left = &n15;
    n20.right = &n7;

    Solution solution;
    std::cout << solution.maxDepth(&n3) << endl;
    return 0;
}

