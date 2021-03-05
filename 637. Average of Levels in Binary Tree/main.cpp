#include <iostream>
#include <vector>
#include <list>

using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    vector<double> averageOfLevels(TreeNode* root) {
        // Runtime: 16 ms,        76%
        // Memory Usage: 22.4 MB, 95%
        vector<double> result;
        vector<TreeNode *> list;
        vector<TreeNode *> nextList;
        list.push_back(root);
        double layerSum = 0;
        int layerNodeCounter = 0;
        while (!list.empty()) {
            TreeNode *node = list.back();
            list.pop_back();
            layerSum += node->val;
            layerNodeCounter++;

            if (node->left != nullptr) {
                nextList.push_back(node->left);
            }
            if (node->right != nullptr) {
                nextList.push_back(node->right);
            }

            if(list.empty()) {
                result.push_back(layerSum / layerNodeCounter);
                layerSum = 0;
                layerNodeCounter = 0;
                list = nextList;
                nextList.clear();
            }
        }

        return result;
    }
};


int main()
{
    /**
     * Main testcase:
     *
     *      3
     *     / \
     *    9  20
     *      /  \
     *     15   7
     *
     */
    TreeNode n3(3);
    TreeNode n9(9);
    TreeNode n20(20);
    TreeNode n15(15);
    TreeNode n7(7);

    n3.left = &n9;
    n3.right = &n20;
    n20.left = &n15;
    n20.right = &n7;

    Solution s;
    const auto res = s.averageOfLevels(&n3);
    cout << "Hello World!" << endl;
    return 0;
}

