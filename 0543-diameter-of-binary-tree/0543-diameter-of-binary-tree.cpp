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
    pair<int,int> diameterfast(TreeNode* root) {
        // Your code here
        if(root==NULL){
            pair<int,int> p=make_pair(0,0);
            return p;
        }
        pair<int,int> left=diameterfast(root->left);
        pair<int,int> right=diameterfast(root->right);
        int op1=left.first;
        int op2=right.first;
        int op3=left.second+right.second+1;
        
        pair<int,int> ans;
        ans.first=max(op1,max(op2,op3)); //this is diameter
        ans.second=max(left.second,right.second)+1; // this is storing the height
        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return diameterfast(root).first-1;
    }
};