class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        int product=1;
        int maxi=nums[0]*nums[1];
        
        for(int i=0;i<n;i++){
            product=product*nums[i];
            
            maxi=max(maxi,product);
            
            if(product==0)
                product=1;
        }
        product=1;
        int maxi2=nums[n-1]*nums[n-2];
        for(int i=n-1;i>=0;i--){
            product=product*nums[i];
            
            maxi2=max(maxi2,product);
            
            if(product==0)
                product=1;
        }
        maxi=max(maxi,maxi2);
        return maxi;
    }
};