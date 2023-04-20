//             KAHN ALGORITHM
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
    
        //indegree vector
        vector<int> indegree(V);
        for(int i=0;i<V;i++){
            for(int j=0;j<adj[i].size();j++){
                indegree[adj[i][j]]++;
            }
        }
    
        //0 indegree push in queue
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
    
        //bfs
        vector<int> ans;
        while(!q.empty()){
            int front=q.front();
            q.pop();
    
            //ans store
            ans.push_back(front);
            //neigbour degree update
            for(int i=0;i<adj[front].size();i++){
                indegree[adj[front][i]]--;
                if(indegree[adj[front][i]]==0)
                q.push(adj[front][i]);
            }
        }
        return ans;
    	}
};
/* CODING NINJAS SUBMISSION
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    //create adj list
    unordered_map<int,list<int>> adj;
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
    }

    //indegree vector
    vector<int> indegree(v);
    for(auto i:adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }

    //0 indegree push in queue
    queue<int> q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    //bfs
    vector<int> ans;
    while(!q.empty()){
        int front=q.front();
        q.pop();

        //ans store
        ans.push_back(front);
        //neigbour degree update
        for(auto neighbour:adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0)
            q.push(neighbour);
        }
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
