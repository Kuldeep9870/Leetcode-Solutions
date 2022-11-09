class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int miss;
        vector<bool> ans(n+1,false);
        for(int i=0;i<n;i++)
        {
            ans[nums[i]]=true;
        }
        for(int i=0;i<=n;i++)
        {
            if(ans[i]==false)
            {
                miss=i;
                break;
            }   
        }
        return miss;
        
    }
};