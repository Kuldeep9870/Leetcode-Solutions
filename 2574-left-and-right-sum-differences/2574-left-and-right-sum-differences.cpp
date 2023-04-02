class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        vector<int> left(n,0);
        vector<int> right(n,0);
        int sum=0;
        for(int i=0;i<nums.size();i++){
            left[i]=sum;
            sum=sum+nums[i];
        }
        sum=0;
        for(int i=nums.size()-1;i>=0;i--){
            right[i]=sum;
            sum=sum+nums[i];
        }
        for(int i=0;i<nums.size();i++){
            ans[i]=abs(left[i]-right[i]);
        }
        return ans;
    }
};