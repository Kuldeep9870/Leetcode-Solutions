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
    void findPath(TreeNode* root,int targetSum,int sum,vector<int>&                 path,vector<vector<int>>& ans){
        if(root==NULL)
            return ;
        if(root->left==NULL && root->right==NULL && targetSum-root->val==0){
            path.push_back(root->val);
            ans.push_back(path);
            path.pop_back();
            return;
        }
        
        targetSum-=root->val;
        path.push_back(root->val);
        
        findPath(root->left,targetSum,sum,path,ans);
        findPath(root->right,targetSum,sum,path,ans);
        
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        
        int sum=0;
        vector<int> path;
        findPath(root,targetSum,sum,path,ans);
        
        
        return ans;
    }
};