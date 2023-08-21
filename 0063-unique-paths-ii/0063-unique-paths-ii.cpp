class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& Grid,vector<vector<int>>& dp){
        if(i>=0 && j>=0 && Grid[i][j]==1)
            return 0;
        if(i==0 && j==0)
            return 1;
        if(i<0 || j<0)
            return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int up=solve(i-1,j,Grid,dp);
        int left=solve(i,j-1,Grid,dp);
        
        return dp[i][j]=up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve( n-1, m-1,obstacleGrid,dp);
    }
};