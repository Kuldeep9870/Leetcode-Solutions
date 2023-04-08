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
    void solve(TreeNode* root,int lvl,int &maxlvl,int& ans){
        if(root==NULL)
            return;
            
        if(lvl>maxlvl){
            maxlvl=lvl;
            ans=root->val;
        }
        
        solve(root->left,lvl+1,maxlvl,ans);
        solve(root->right,lvl+1,maxlvl,ans);
    }
    int findBottomLeftValue(TreeNode* root) {
        int maxlvl=-1;
        int lvl=-1;
        int ans=0;
        solve(root,lvl+1,maxlvl,ans);
        return ans;
    }
};