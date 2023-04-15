/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void solve(TreeNode* root,TreeNode* target,TreeNode*& reference){
        if(root==NULL)
            return;
        
        if(root->val==target->val){
            reference=root;
            return;
        }
        
        solve(root->left,target,reference);
        solve(root->right,target,reference);
            
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* reference=NULL;
        solve(cloned,target,reference);
        return reference;
    }
};