/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int min_diff = INT_MAX;
    TreeNode* prev = nullptr;

    int minDiffInBST(TreeNode* root) {
        inorder(root);
        return min_diff;
    }

private:
    void inorder(TreeNode* node) {
        if (!node) return;

        // Traverse left subtree
        inorder(node->left);

        // Process current node
        if (prev != nullptr) {
            min_diff = min(min_diff, node->val - prev->val);
        }
        prev = node; // Update the previous node pointer

        // Traverse right subtree
        inorder(node->right);
    }
};
