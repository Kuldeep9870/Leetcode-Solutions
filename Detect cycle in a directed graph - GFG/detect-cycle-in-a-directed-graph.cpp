//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node,vector<int> &vis,vector<bool> &dfsvisit,vector<int> adj[]){
        vis[node]=true;
        dfsvisit[node]=true;
        
        for(auto i:adj[node]){
            if(!vis[i]){
                bool cycle=dfs(i,vis,dfsvisit,adj);
                if(cycle)
                    return true;
            }
            else if(dfsvisit[i])
                return true;
        }
        dfsvisit[node]=false;
        return false;
    }
  
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> ans;
        vector<int> vis(V,0);
        vector<bool> dfsvisit(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                bool cycle=dfs(i,vis,dfsvisit,adj);
                if(cycle)
                    return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends