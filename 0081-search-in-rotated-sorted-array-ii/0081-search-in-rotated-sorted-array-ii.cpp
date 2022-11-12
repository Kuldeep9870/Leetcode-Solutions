class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0,h=nums.size()-1; 
        while(l<=h)
        {
            if(nums[l]==target)
            {
                return true;
            }
            l++;
            if(nums[h]==target)
            {
                return true;
            } 
            h--;
        }
        return false;
        
    }
};