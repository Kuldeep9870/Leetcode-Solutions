//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool iscycleDFS(int node,int parent,vector<int> adj[],unordered_map<int,bool>& visited){
    visited[node]=true;

    for(int i=0;i<adj[node].size();i++){
        if(!visited[adj[node][i]]){
            bool cycleDetect=iscycleDFS(adj[node][i], node, adj, visited);
            if(cycleDetect==true)
            return true;
        }
        else if (adj[node][i]!=parent){
            return true;
        }
    }
    return false;
}
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        // unordered_map<int,list<int>> adjList;
        // //conversion to mapped adj list
        // for(int i=0;i<V;i++){
        //     for(int j=0;j<adj[i].size();j++){
        //         adjList[i].push_back(adj[i][j]);
        //     }
        // }
        unordered_map<int,bool> visited;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bool cycle=iscycleDFS(i,-1,adj,visited);
                if(cycle)
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends