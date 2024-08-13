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
    void traverse(TreeNode* root, int& count, int k, int& ans){
        if(count==k) return;
        if(root==NULL) return;
        traverse(root->left,count,k,ans);
        count++;
        if(count==k){
            ans=root->val;
        }
        traverse(root->right,count,k,ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        int count=0;
        int ans=0;
        traverse(root,count,k,ans);
        return ans;
    }
};