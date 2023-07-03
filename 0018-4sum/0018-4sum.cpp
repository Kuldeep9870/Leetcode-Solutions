class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> s;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n-2;i++){
            
            for(int j=i+1;j<n-2;j++){
                
                //two pointers
                int l=j+1;
                int h=n-1;
                
                while(l<h){
                    long sum=1LL*nums[i]+1LL*nums[j]+ 1LL*nums[l]+ 1LL*nums[h];
                    
                    if(sum==1LL*target){
                        
                    s.insert({nums[i],nums[j],nums[l],nums[h]});
                        
                    while(l<h && nums[l]==nums[l+1]) l++;
                    while(l<h && nums[h]==nums[h-1]) h--;
                        
                    l++;
                    h--;
                    }
                    else if(sum<1LL*target) l++;
                    else h--;
                }
            }
        }
        vector<vector<int>> ans;
        for(auto i:s){
            ans.push_back(i);
        }
        return ans;
    }
};