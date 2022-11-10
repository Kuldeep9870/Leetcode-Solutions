class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            ans=ans^nums[i];
        }
        return ans;
        
        //xor of same number is zero ---- 5^5=0   5^0=5
        
        
    }
};