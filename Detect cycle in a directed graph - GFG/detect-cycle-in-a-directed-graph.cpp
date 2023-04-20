//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  bool checkcycleDFS(int node,vector<int> adj[],
    unordered_map<int,bool>& visited,unordered_map<int,bool>& DFSvisited){
      visited[node]=true;
      DFSvisited[node]=true;
    
      for(int i=0;i<adj[node].size();i++){
        if(!visited[adj[node][i]]){
          bool cycle=checkcycleDFS(adj[node][i], adj, visited, DFSvisited);
          if(cycle)
          return true;
        }
        else if(DFSvisited[adj[node][i]]==true){
          return true;
        }
      }
      DFSvisited[node]=false;
      return false;
}
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        unordered_map<int,bool> visited;
        unordered_map<int,bool> DFSvisited;
    
      //call for dfs for all components
      for(int i=0;i<V;i++){
        if(!visited[i]){
          bool cyclefound=checkcycleDFS(i,adj,visited,DFSvisited);
          if(cyclefound)
          return true;
        }
      }
      return false;
    }
};
/*  CODING NINJAS CYCLE DETECTION SUBMISSION
bool checkcycleDFS(int node,unordered_map<int,list<int>>& adj,
unordered_map<int,bool>& visited,unordered_map<int,bool>& DFSvisited){
  visited[node]=true;
  DFSvisited[node]=true;

  for(auto neighbour:adj[node]){
    if(!visited[neighbour]){
      bool cycle=checkcycleDFS(neighbour, adj, visited, DFSvisited);
      if(cycle)
      return true;
    }
    else if(DFSvisited[neighbour]==true){
      return true;
    }
  }
  DFSvisited[node]=false;
  return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  unordered_map<int,list<int>> adj;
  for(int i=0;i<edges.size();i++){
    int u=edges[i].first;
    int v=edges[i].second;
    adj[u].push_back(v);
  }
  unordered_map<int,bool> visited;
  unordered_map<int,bool> DFSvisited;

  //call for dfs
  for(int i=1;i<=n;i++){
    if(!visited[i]){
      bool cyclefound=checkcycleDFS(i,adj,visited,DFSvisited);
      if(cyclefound)
      return true;
    }
  }
  return false;
}*/

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