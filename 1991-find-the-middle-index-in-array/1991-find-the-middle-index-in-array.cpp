class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n=nums.size();
        int totalsum=0,leftsum=0;
        for(auto i:nums){
            totalsum+=i;
        }
        for(int i=0;i<n;i++){
            if(leftsum==totalsum-leftsum-nums[i])
                return i;
            
            leftsum+=nums[i];
        }
        return -1;
    }
};