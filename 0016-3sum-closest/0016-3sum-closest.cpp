class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans=INT_MIN;
        int n=nums.size();
        int prevDiff=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            int low=i+1;
            int high=n-1;
            int sum=nums[i];
             while(low< high){
                    sum=nums[i]+nums[low]+nums[high];
                    if(sum==target){
                        return sum;

                        while(low <high && nums[low]==nums[low+1]) low++;
                        while(low <high && nums[high]==nums[high-1]) high--;

                        low++;
                        high--;
                    }
                    else if(sum<target){
                        int d=abs(sum-target);
                        if(d<prevDiff){
                            ans=sum;
                            prevDiff=d;
                        }
                        low++;
                    }
                    else{
                        int d=abs(sum-target);
                        if(d<prevDiff){
                            ans=sum;
                            prevDiff=d;
                        }
                        high--;
                    }
                }
        }
        return ans;
    }
};