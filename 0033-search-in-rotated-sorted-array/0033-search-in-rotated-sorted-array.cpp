class Solution {
public:
    int pivot(vector<int>& nums){
        int n=nums.size();
        
        int s=0;
        int e=n-1;
        if(nums[s]<nums[e])
            return s;
        while(s<e){
            int mid=s+(e-s)/2;
            if(nums[mid]>=nums[0]){
                s=mid+1;
            }
            else{
                e=mid;
            }
        }
        return s;
    }
    int binary(vector<int>& nums, int target, int s,int e){
        int n=nums.size();
        
        
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        if(target == nums[0]) return 0;
        
        int n=nums.size();
        int p=pivot(nums);
        if(target>=nums[p] && target <= nums[n-1])
            return binary(nums,target,p,n-1);
        else
            return binary(nums,target,0,p-1);
    }
};