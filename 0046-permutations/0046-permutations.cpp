class Solution {
public:
    void solve(vector<int> nums,int index,vector<vector<int>>& ans)
    {
        //base case
        if(index>=nums.size())
        {
            ans.push_back(nums);
            return;
        }
        
        for(int j=index;j<nums.size();j++)
        {
            swap(nums[index],nums[j]);
            
            solve(nums,index+1,ans);
            
            //backtrack to correct and revert the array to original
            swap(nums[index],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int index=0;
        vector<vector<int>> ans;
        
        solve(nums,index,ans);
        
        return ans;
        
    }
};