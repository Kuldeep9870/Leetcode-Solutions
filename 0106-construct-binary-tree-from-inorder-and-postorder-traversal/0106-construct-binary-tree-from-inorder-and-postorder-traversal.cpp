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
    void createMap(map<int,int> &m,vector<int> in){
        for(int i=0;i<in.size();i++){
            m[in[i]]=i;
        }
    }
    TreeNode* solve(vector<int> in,vector<int> post,int &index,int inStart,int inEnd,map<int,int> &m){
        if(index<0 || inStart>inEnd)
        return NULL;
        
        int element=post[index];
        index--;
        TreeNode* root=new TreeNode(element);
        int position=m[element];
        
        //recursive call
        root->right=solve(in,post,index,position+1,inEnd,m);
        root->left=solve(in,post,index,inStart,position-1,m);
        
        
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postindex=postorder.size()-1;
        map<int,int> m;
        
        createMap(m,inorder);
        TreeNode* ans=solve(inorder,postorder,postindex,0,postorder.size()-1,m);
        return ans;
        
    }
};