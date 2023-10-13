class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> left(n),right(n);
        vector<int> ans(n);
        left[0]=nums[0];
        right[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            left[i]=left[i-1]*nums[i];
            right[n-1-i]=right[n-i]*nums[n-1-i];
        }
        for(int i=0;i<n;i++){
            int leftans=1,rightans=1;
            if(i-1>=0)
                leftans=left[i-1];
            if(i+1<n)
                rightans=right[i+1];
            ans[i]=leftans*rightans;
        }
        return ans;
        
        
    }
};