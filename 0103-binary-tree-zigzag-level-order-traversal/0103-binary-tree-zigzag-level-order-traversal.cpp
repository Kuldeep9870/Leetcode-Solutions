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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        
        //direction flag
        bool leftToright=true;
        
        while(!q.empty()){
            int size=q.size();
            vector<int> ans(size);
            
            for(int i=0;i<size;i++){
                TreeNode* temp=q.front();
                q.pop();
                
                int index=leftToright?i:size-i-1;
                ans[index]=temp->val;
                
                if(temp->left)
                    q.push(temp->left);
                
                if(temp->right)
                    q.push(temp->right);
                
                
            }
            //direction change
            leftToright=!leftToright;
            
            res.push_back(ans);
            ans.clear();
        }
        return res;
    }
};