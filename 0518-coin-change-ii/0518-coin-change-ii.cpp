class Solution {
public:
    int solve(int ind,vector<int>& coins, int amount,vector<vector<int>>& dp){
        if(ind==0){
            if( amount%coins[0]==0){
                return 1;
            }
            else
                return 0;
        }
        
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int nottake= solve(ind-1,coins,amount,dp);
        int take=0;
        if(amount>=coins[ind])
            take=  solve(ind,coins,amount-coins[ind],dp);
        
        return dp[ind][amount]=take+ nottake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        
        int ans=solve(n-1,coins,amount,dp);
        
        return ans;
    }
};