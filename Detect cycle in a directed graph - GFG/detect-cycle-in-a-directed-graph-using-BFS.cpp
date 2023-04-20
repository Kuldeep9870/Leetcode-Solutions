// this submission is from CODING NINJAS
#include <bits/stdc++.h> 
#include <unordered_map>
#include <queue>
#include <list>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges)  {
    // Write your code here
    //create adj list
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first-1;
        int v=edges[i].second-1;

        adj[u].push_back(v);
    }

    //indegree vector
    vector<int> indegree(n);
    for(auto i:adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }

    //0 indegree push in queue
    queue<int> q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    //bfs
    int cnt=0;
    while(!q.empty()){
        int front=q.front();
        q.pop();

        //ans store
        cnt++;
        //neigbour degree update
        for(auto neighbour:adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0)
            q.push(neighbour);
        }
    }
    if(cnt==n) 
      return false;
    else
      return true;
}
