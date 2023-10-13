class Solution {
public:
    int bfs(int row,int col ,vector<vector<int>>& grid,vector<vector<bool>>& vis){
        vis[row][col]=1;
        
        int n=grid.size();
        int m=grid[0].size();
        int area=1;
        
        queue<pair<int,int>> q;
        q.push({row,col});
        
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int newrow=r+dx[i];
                int newcol=c+dy[i];
                
                if(newrow<n && newrow>=0 && newcol>=0 && newcol<m && !vis[newrow][newcol] &&                        grid[newrow][newcol]==1){
                    area++;
                    
                    vis[newrow][newcol]=1;
                    q.push({newrow,newcol});
                }
            }
        }
        return area;
       
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    int area=bfs(i,j,grid,vis);
                    ans=max(ans,area);
                }
            }
        }
        return ans;
    }
};