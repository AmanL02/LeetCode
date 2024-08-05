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
    void traverse(TreeNode* root, vector<char>& temp){
        if(root==NULL){
            temp.push_back('n');
            return;
        }
        temp.push_back(root->val);
        traverse(root->left,temp);
        traverse(root->right,temp);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<char> temp1;
        vector<char> temp2;
        traverse(p,temp1);
        traverse(q,temp2);
        int n=temp1.size();
        int m=temp2.size();
        if(n!=m) return false;
        for(int i=0;i<n;i++){
            if(temp1[i]!=temp2[i]){
                return false;
            }
        }
        return true;
    }
};