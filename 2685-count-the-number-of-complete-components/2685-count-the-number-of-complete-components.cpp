class Solution {
private:
    void dfs(int node,vector<int> adj[],vector<bool> &vis,vector<int> &compNodes){
        vis[node]=true;
        compNodes.push_back(node);
        for(auto i:adj[node]){
            if(!vis[i])
                dfs(i,adj,vis,compNodes);
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        //create adj list
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> vis(n);
        vector<vector<int>> component;
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vector<int> compNodes;
                dfs(i,adj,vis,compNodes);
                component.push_back(compNodes);
            }
        }
        int temp=0;
        int count=0;
        //Checking for the complete component
        /*Logic is that if in a component if every node has n-1 edges and 
        n is no of node in that component*/
        for(int i=0;i<component.size();i++){
            int compNo=component[i].size();
            for(int j=0;j<component[i].size();j++){
                if(adj[component[i][j]].size()==compNo-1){
                    temp++;
                }
            }
            if(temp==compNo)
                count++;
            
            temp=0;
            
        }
        return count;
    }
};