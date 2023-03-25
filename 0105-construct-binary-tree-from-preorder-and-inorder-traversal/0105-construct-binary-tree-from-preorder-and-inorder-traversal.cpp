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
    void createMap(map<int,int> &m,vector<int> in,int n){
        for(int i=0;i<n;i++){
            m[in[i]]=i;
        }
    }
    TreeNode* solve(vector<int> in, vector<int> pre,int &index,int inStart,int inEnd,int n,map<int,int> &m){
        if(index>=n || inStart>inEnd)
        return NULL;
        
        int element=pre[index];
        index++;
        TreeNode* root=new TreeNode(element);
        int position=m[element];
        
        //recursive call
        root->left=solve(in,pre,index,inStart,position-1,n,m);
        
        root->right=solve(in,pre,index,position+1,inEnd,n,m);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preindex=0;
        map<int,int> m;
        createMap(m,inorder,inorder.size());
        TreeNode* root=solve(inorder,preorder,preindex,0,inorder.size()-1,preorder.size(),m);
        return root;
    }
};