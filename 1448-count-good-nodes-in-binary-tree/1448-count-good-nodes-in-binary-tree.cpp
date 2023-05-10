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
    void find(TreeNode* root,int&count,int value){
        if(root==NULL)
            return;
        
        
        if(root->val>=value){
            count++;
            value=root->val;
        }

        find(root->left,count,value);
        find(root->right,count,value);
        
    }
    int goodNodes(TreeNode* root) {
        int count=0;
        find(root,count,root->val);
        return count;
    }
};