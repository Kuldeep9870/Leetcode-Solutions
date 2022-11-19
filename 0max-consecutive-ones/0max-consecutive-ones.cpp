class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max=-1;
        int tmpcount=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
                tmpcount++;
            else
                tmpcount=0;
            
            if(tmpcount>max)
                max=tmpcount;
        }
        return max;
    }
};