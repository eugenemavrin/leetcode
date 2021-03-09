#include <iostream>
#include <vector>

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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        // Runtime: 16 ms,      90%
        // Memory Usage: 25 MB, 54%
        if (d == 1) {
            TreeNode *node = new TreeNode(v);
            node->left = root;
            return node;
        }

        vector<TreeNode *> layerNodes;
        vector<TreeNode *> nextLayerNodes;
        vector<TreeNode *> backup;
        int layerDepth = 1;
        layerNodes.push_back(root);
        while (layerNodes.size() > 0) {
            TreeNode * node = layerNodes.back();
            backup.push_back(node);
            layerNodes.pop_back();

            if (node->left != nullptr)
                nextLayerNodes.push_back(node->left);

            if (node->right != nullptr)
                nextLayerNodes.push_back(node->right);

            if (layerNodes.size() == 0) {
                if (layerDepth == d - 1) {
                    for(TreeNode *n : backup) {
                        TreeNode *nl = new TreeNode(v);
                        nl->left = n->left;
                        n->left = nl;
                        TreeNode *nr = new TreeNode(v);
                        nr->right = n->right;
                        n->right = nr;
                    }
                    nextLayerNodes.clear();
                }

                layerNodes = nextLayerNodes;
                layerDepth++;
                nextLayerNodes.clear();
                backup.clear();
            }
        }

        return root;
    }
};

int main()
{

    /** Main Testcase:
     *
     *        4
     *      /   \
     *     2     6
     *    / \   /
     *   3   1 5
     *
     */

    TreeNode n4(4);
    TreeNode n2(2);
    TreeNode n6(6);
    TreeNode n3(3);
    TreeNode n1(1);
    TreeNode n5(5);

    n4.left = &n2;
    n4.right = &n6;
    n2.left = &n3;
    n2.right = &n1;
    n6.left = &n5;

    Solution s;
    const auto result = s.addOneRow(&n4, 5, 4);
    cout << result->val << endl;
    return 0;
}
