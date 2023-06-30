class Solution {
public:
    int sum(vector<int>& nums,int l,int r){
        int sum=0;
        for(int i=l;i<=r;i++){
            sum=sum+nums[i];
        }
        return sum;
    }
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> m;
        int i,j;
        i=j=0;
        int ans=0;
        
        while(j<nums.size()){
            m[nums[j]]++;
            if(m.size()==(j-i+1)){ //equal size to window
                int uniqSum=sum(nums,i,j);
                ans=max(ans,uniqSum);
            }
            else if(m.size()<j-i+1){
                
                while(m.size()<j-i+1){
                    m[nums[i]]--;
                    if(m[nums[i]]==0){
                        m.erase(nums[i]);
                    }
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};