class Solution {
public:
    int reverse(int x) { 
        int ans=0;
        while(x!=0){
            int r=x%10;
            
            ans=ans*10+r;
            x/=10;
        }
        return ans;
    }
    int countDistinctIntegers(vector<int>& nums) {
        unordered_map<int,bool> m;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int rev=reverse(nums[i]);
            m[nums[i]]=true;
            m[rev]=true;
        }
        
        return m.size();
    }
};