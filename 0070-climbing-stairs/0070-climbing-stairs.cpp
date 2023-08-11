class Solution {
public:
    int getWays(int n,vector<int> &dp){
     if(n==0 || n==1)
        return 1;
    if(n<0)
        return n;
    if(dp[n]!=-1)
        return dp[n];
    
    int left = getWays(n - 1, dp);
    int right = getWays(n - 2, dp);

    return dp[n] = (left + right);
     
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return getWays(n,dp);
    }
};