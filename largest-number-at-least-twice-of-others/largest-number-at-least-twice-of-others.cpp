class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max=INT_MIN;
        int pos=-1;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(max<nums[i])
            {
                pos=i;
                max=nums[i];
            }
        }
        for(int i=0;i<n;i++)
        {
            if(i==pos)
                continue;
            if(max<2*nums[i])
            {
                return -1;
            }
        }
        return pos;
        
    }
};