class Solution {
public:
    int getPivot(vector<int>& nums){
        int s=0;
        int e=nums.size()-1;
        
        if(nums[s]<nums[e])
            return s;
        
        while(s<e){
            int mid=s+(e-s)/2;
            if(nums[mid]>=nums[0]){
                s=mid+1;
            }
            else
                e=mid;
        }
        return s;
    }
    int binarysearch(vector<int>& nums, int target,int s,int e){
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
                e=mid-1;
            else
                s=mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int pivot=getPivot(nums);
        int n=nums.size();
        
        
        if(target>=nums[pivot] && target<=nums[n-1])
            return binarysearch(nums,target,pivot,nums.size()-1);
        else
            return binarysearch(nums,target,0,pivot-1);
        

    }
};



/*  TWO POINTER : NAIVE APPROACH
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
*/