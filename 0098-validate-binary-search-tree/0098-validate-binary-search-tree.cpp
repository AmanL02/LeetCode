/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void traverse(TreeNode* root, bool& flag, long long& temp) {
        if (!flag || !root)
            return;
        traverse(root->left, flag, temp);
        if (root->val <= temp) {
            flag = false;
            return;
        }
        temp = root->val;
        traverse(root->right, flag, temp);
    }

    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;
        bool flag = true;
        long long temp =
            (long long)INT_MIN -
            1; // Initialize temp with a value less than any possible node value
        traverse(root, flag, temp);
        return flag;
    }
};