//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        vector<int> dist(V,1e8);
        dist[S]=0;
    
        //n-1 times  or V-1 times
        for(int i=1;i<=V;i++){
            for(int j=0;j<edges.size();j++){
                int u=edges[j][0];
                int v=edges[j][1];
                int wt=edges[j][2];
    
    
                if(dist[u]!=1e8 && ((dist[u]+wt)<dist[v])){
                    dist[v]=dist[u]+wt;
                }
            }
        }
        int flag=0;
        //check for -ve cycle
        for(int j=0;j<edges.size();j++){
                int u=edges[j][0];
                int v=edges[j][1];
                int wt=edges[j][2];
    
    
                if(dist[u]!=1e8 && ((dist[u]+wt)<dist[v])){
                    flag=1;
                    break;
                }
            }
    
        if(flag==0)
        return dist;
    
        return {-1};
    }
};

/*  CODING NINJAS BELLMAN FORD ALGO
#include <bits/stdc++.h> 
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<int> dist(n+1,1e9);
    dist[src]=0;

    //n-1 times
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            int u=edges[j][0];
            int v=edges[j][1];
            int wt=edges[j][2];


            if(dist[u]!=1e9 && ((dist[u]+wt)<dist[v])){
                dist[v]=dist[u]+wt;
            }
        }
    }

    int flag=0;
    //check for -ve cycle
    for(int j=0;j<m;j++){
            int u=edges[j][0];
            int v=edges[j][1];
            int wt=edges[j][2];


            if(dist[u]!=1e9 && ((dist[u]+wt)<dist[v])){
                flag=1;
                break;
            }
        }

    if(flag==0)
    return dist[dest];

    return -1;
}
*/

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends