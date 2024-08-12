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
    bool traverse(TreeNode* node1, TreeNode* node2){
        if(node1==NULL && node2==NULL){
            return true;
        }
        if(node1==NULL || node2==NULL){
            return false;
        }
        if(node1->val !=node2->val){
            return false;
        }
        bool flag1=traverse(node1->left,node2->right);
        bool flag2=traverse(node1->right,node2->left);
        if(flag1 && flag2) return true;
        return false;
    }

    bool isSymmetric(TreeNode* root) {
        TreeNode* node1=root;
        TreeNode* node2=root;
        return traverse(node1->left,node2->right);
    }
};