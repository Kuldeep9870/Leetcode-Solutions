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
    bool check(TreeNode* root,int& value){
        if(root==NULL){
            return true;
        }
        if(root->val!=value)
            return false;
        
        bool left=check(root->left,value);
        bool right=check(root->right,value);
        
        return left&&right;
    }
    bool isUnivalTree(TreeNode* root) {
        return check(root,root->val);
    }
};