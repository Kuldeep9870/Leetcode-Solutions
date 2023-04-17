//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool isSafe(int x,int y,int n,vector<vector<int>> &m,vector<vector<bool>>& vis){
        if((x>=0&& x<n)&& (y>=0 && y<n)&& vis[x][y]==0&& m[x][y]==1)
        return true;
        else
        return false;
    }
    void solve(int x,int y,int n,vector<vector<int>> &m,vector<string>& ans,vector<vector<bool>>& vis,string path){
        //base case
        if(x==n-1 && y==n-1){
            ans.push_back(path);
            return;
        }
        
        //lexical order---> D L R U
        //DOWN
        if(isSafe(x+1,y,n,m,vis)){
            vis[x][y]=1;
            solve(x+1,y,n,m,ans,vis,path+'D');
            vis[x][y]=0;
        }
        //LEFT
        if(isSafe(x,y-1,n,m,vis)){
            vis[x][y]=1;
            solve(x,y-1,n,m,ans,vis,path+'L');
            vis[x][y]=0;
        }
        //right
        if(isSafe(x,y+1,n,m,vis)){
            vis[x][y]=1;
            solve(x,y+1,n,m,ans,vis,path+'R');
            vis[x][y]=0;
        }
        //UP
        if(isSafe(x-1,y,n,m,vis)){
            vis[x][y]=1;
            solve(x-1,y,n,m,ans,vis,path+'U');
            vis[x][y]=0;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<bool>> vis(n,vector<bool>(n,0));
        vector<string> ans;
        string path;
        
        if(m[0][0]==0)
        return ans;
        
        solve(0,0,n,m,ans,vis,path);
        
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends