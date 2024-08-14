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
    void traverse(TreeNode* root, vector<int>& temp){
        if(root==NULL) return;
        traverse(root->left,temp);
        temp.push_back(root->val);
        traverse(root->right,temp);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> temp;
        traverse(root,temp);
        int n=temp.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(temp[i]+temp[j]==k){
                    return true;
                }
            }
        }
        return false;
    }
};