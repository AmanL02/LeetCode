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
    void traverse(TreeNode* root, int row, int col, map<pair<int, int>, vector<int>>& mpp) {
        if (root == NULL) return;
        mpp[{row, col}].push_back(root->val);
        traverse(root->left, row + 1, col - 1, mpp);
        traverse(root->right, row + 1, col + 1, mpp);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<pair<int, int>, vector<int>> mpp;
        traverse(root, 0, 0, mpp);

        int maxi = INT_MIN;
        int mini = INT_MAX;
        for (auto i : mpp) {
            maxi = max(maxi, i.first.second);
            mini = min(mini, i.first.second);
        }

        vector<vector<int>> ans(maxi - mini + 1);

        for (auto i : mpp) {
            sort(i.second.begin(), i.second.end());
            for(auto x: i.second)
            {
                ans[i.first.second - mini].push_back(x);
            }
            
        }

        return ans;
    }
};
