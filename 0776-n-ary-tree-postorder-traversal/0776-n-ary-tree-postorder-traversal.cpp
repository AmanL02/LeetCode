/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void traverse(Node* root, vector<int>& ans){
        if(!root){
            return;
        }
        for(auto i : root->children){
            traverse(i,ans);
        }
        ans.push_back(root->val);
    }

    vector<int> postorder(Node* root) {
        if(root==NULL) return {};
        vector<int> ans;
        traverse(root,ans);
        return ans;
    }
};