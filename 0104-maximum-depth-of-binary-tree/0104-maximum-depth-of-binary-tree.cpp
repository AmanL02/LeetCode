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

    int maxi=0;
    void traverse(TreeNode* root, int count){
        maxi=max(maxi,count);
        if(root==NULL) return;
        traverse(root->left,count+1);
        traverse(root->right,count+1);
    }
    int maxDepth(TreeNode* root) {
        traverse(root,0);
        return maxi;
    }
};