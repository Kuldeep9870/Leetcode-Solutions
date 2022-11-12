class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,h=nums.size()-1; 
        while(l<=h)
        {
            if(nums[l]==target)
            {
                return l;
            }
            else 
            l++;
            if(nums[h]==target)
            {
                return h;
            }
            else 
            h--;
        }
        return -1;
        
    }
};