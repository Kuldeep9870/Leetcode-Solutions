//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void dfs(int node,vector<vector<int>>& adj,stack<int>& st,vector<int>& vis){
    	vis[node]=true;
    
    	for(auto nbr:adj[node]){
    		if(!vis[nbr])
    		dfs(nbr, adj, st, vis);
    	}
    
    	st.push(node);
    }
    void revDfs(int node,unordered_map<int,list<int>>& adj,vector<int>& vis){
    	vis[node]=true;
    
    	for(auto nbr:adj[node]){
    		if(!vis[nbr])
    		revDfs(nbr, adj, vis);
    	}
    
    }
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        
    	stack<int> st;
    	vector<int> vis(V);
    	//topo sort
    	for(int i=0;i<V;i++){
    		if(!vis[i])
    		dfs(i, adj, st, vis);
    	}
    
    
    	//tranpose
    	unordered_map<int,list<int>> transpose;
    	for(int i=0;i<V;i++){
    		vis[i]=false;
    		for(auto nbr: adj[i]){
    			transpose[nbr].push_back(i);
    		}
    	}
    
    	//dfs for topo sorted nodes
    	int count=0;
    	while(!st.empty()){
    		int top=st.top();
    		st.pop();
    
    		if(!vis[top]){
    			count++;
    			revDfs(top, transpose, vis);
    		}
    	}
    	return count;
    }
};

/*  CODING NINJAS KOSRAJU ALGO SUBMISSION
#include <unordered_map>
#include <list>
#include <stack>
void dfs(int node,unordered_map<int,list<int>>& adj,stack<int>& st,vector<int>& vis){
	vis[node]=true;

	for(auto nbr:adj[node]){
		if(!vis[nbr])
		dfs(nbr, adj, st, vis);
	}

	st.push(node);
}
void revDfs(int node,unordered_map<int,list<int>>& adj,vector<int>& vis){
	vis[node]=true;

	for(auto nbr:adj[node]){
		if(!vis[nbr])
		revDfs(nbr, adj, vis);
	}

}
int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	// Write your code here.
	//adj list
	unordered_map<int,list<int>> adj;
	for(int i=0;i<edges.size();i++){
		int u=edges[i][0];
		int v=edges[i][1];

		adj[u].push_back(v);
	}

	stack<int> st;
	vector<int> vis(v);
	//topo sort
	for(int i=0;i<v;i++){
		if(!vis[i])
		dfs(i, adj, st, vis);
	}


	//tranpose
	unordered_map<int,list<int>> transpose;
	for(int i=0;i<v;i++){
		vis[i]=false;
		for(auto nbr: adj[i]){
			transpose[nbr].push_back(i);
		}
	}

	//dfs for topo sorted nodes
	int count=0;
	while(!st.empty()){
		int top=st.top();
		st.pop();

		if(!vis[top]){
			count++;
			revDfs(top, transpose, vis);
		}
	}
	return count;
}

*/

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends