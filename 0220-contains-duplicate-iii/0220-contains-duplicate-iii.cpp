class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n && j<=i+indexDiff;j++){
                if(abs(nums[i]-nums[j])<=valueDiff){
                    return true;
                }
            }
        }
        return false;
        
    }
};