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
    int temp=0;

    int traverse(TreeNode* root){
        if(root==NULL) return 0;
        int l=traverse(root->left);
        int r=traverse(root->right);
        temp=max(temp,l+r);
        return max(l,r)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans=traverse(root);
        return temp;
    }
};