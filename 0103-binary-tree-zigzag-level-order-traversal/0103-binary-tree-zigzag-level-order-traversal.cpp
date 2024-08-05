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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL)
            return {};
        queue<TreeNode*> qt;
        qt.push(root);
        int count = 1;
        while (!qt.empty()) {
            int size = qt.size();
            vector<int> temp;
            for (int i = 0; i < size; i++) {
                TreeNode* rooty = qt.front();
                qt.pop();
                if (rooty->left != NULL) {
                    qt.push(rooty->left);
                }
                if (rooty->right != NULL) {
                    qt.push(rooty->right);
                }
                temp.push_back(rooty->val);
            }
            if(count%2==0){
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);
            }else{
                ans.push_back(temp);
            }
            count++;
        }
        return ans;
    }
};