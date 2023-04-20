//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void toposort(int node,vector<int> adj[],
    vector<bool>& visited,stack<int>& s){
        visited[node]=true;
    
        for(int i=0;i<adj[node].size();i++){
            if(!visited[adj[node][i]]){
                toposort(adj[node][i],adj,visited,s);
            }
        }
    
        s.push(node);
    }
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    //call for dfs topological sort for all components
        vector<bool> visited(V);
        stack<int> s;
        for(int i=0;i<V;i++){
            if(!visited[i])
            toposort(i,adj,visited,s);
        }
        vector<int> ans;
    
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
	}
};
/* Coding ninjas Submission
void toposort(int node,unordered_map<int,list<int>>& adj,
vector<bool>& visited,stack<int>& s){
    visited[node]=true;

    for(auto neighbour:adj[node]){
        if(!visited[neighbour]){
            toposort(neighbour,adj,visited,s);
        }
    }

    s.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    //create adj list
    unordered_map<int,list<int>> adj;
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
    }

    //call for dfs topological sort for all components
    vector<bool> visited(v);
    stack<int> s;
    for(int i=0;i<v;i++){
        if(!visited[i])
        toposort(i,adj,visited,s);
    }
    vector<int> ans;

    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
*/

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends
