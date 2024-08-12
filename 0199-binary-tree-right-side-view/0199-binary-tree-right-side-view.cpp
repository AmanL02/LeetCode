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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == NULL)
            return ans;
        queue<TreeNode*> qt;
        qt.push(root);
        while (!qt.empty()) {
            int size = qt.size();
            vector<int> temp;
            for (int i = 0; i < size; i++) {
                TreeNode* rooty = qt.front();
                qt.pop();
                if (rooty->left != NULL)
                    qt.push(rooty->left);
                if (rooty->right != NULL)
                    qt.push(rooty->right);
                temp.push_back(rooty->val);
            }
            ans.push_back(temp[size-1]);
        }
        return ans;
    }
};