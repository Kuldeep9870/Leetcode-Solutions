class Solution {
public:
    int solve(int ind,vector<int>& coins, int amount,vector<vector<int>>& dp){
        if(ind==0){
            if( amount%coins[0]==0)
                return amount/coins[0];
            else
                return 1e9;
        }
        
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int nottake=0 +solve(ind-1,coins,amount,dp);
        int take=1e9;
        if(amount>=coins[ind])
            take= 1 + solve(ind,coins,amount-coins[ind],dp);
        
        return dp[ind][amount]=min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0)
            return 0;
        
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        
        int ans=solve(n-1,coins,amount,dp);
        
       if(ans==1e9) return -1;
        return ans;
    }
};