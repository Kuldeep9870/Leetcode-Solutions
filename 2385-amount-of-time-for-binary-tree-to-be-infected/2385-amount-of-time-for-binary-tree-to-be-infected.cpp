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
    TreeNode* createMapping(TreeNode* root,map<TreeNode*,TreeNode*> &NodeToparent,int target){
      queue<TreeNode*> q;
      q.push(root);
      TreeNode* res=NULL;
      NodeToparent[root]=NULL;
      while(!q.empty()){
          TreeNode* front=q.front();
          q.pop();
          
          if(front->val==target){
              res=front;
          }
          if(front->left){
              q.push(front->left);
              NodeToparent[front->left]=front;
          }
          if(front->right){
              q.push(front->right);
              NodeToparent[front->right]=front;
          }
      }
      return res;
  }
  int BurnTree(TreeNode* root,map<TreeNode*,TreeNode*> NodeToparent){
      int count=0;
      map<TreeNode*,bool> visited;
      visited[root]=true;
      queue<TreeNode*> q;
      int flag=0;
      q.push(root);
      while(!q.empty()){
          flag=0;
          int size=q.size();
          for(int i=0;i<size;i++){
              TreeNode* front=q.front();
              q.pop();
              
          if(front->left && visited[front->left]!=true){
              flag=1;
              visited[front->left]=true;
              q.push(front->left);
          }
          if(front->right && visited[front->right]!=true){
              flag=1;
              visited[front->right]=true;
              q.push(front->right);
          }
          if(NodeToparent[front] && visited[NodeToparent[front]]!=true){
              flag=1;
              visited[NodeToparent[front]]=true;
              q.push(NodeToparent[front]);
          }
          
          }
          
          if(flag==1)
          count++;
      }
      return count;
  }
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*> NodeToparent;
        TreeNode* targetNode;
        targetNode=createMapping(root,NodeToparent,start);
        int count;
        //cout<<"map done";
        count=BurnTree(targetNode,NodeToparent);
        return count;
    }
};