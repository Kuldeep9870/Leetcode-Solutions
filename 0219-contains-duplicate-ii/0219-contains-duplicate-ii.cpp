class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // if(nums.size()<k)
        //     return false;
        
        //key,{occurence,last pos}
        unordered_map<int,pair<int,int>> m;
        for(int i=0;i<nums.size();i++)
        {
           m[nums[i]].first++;
           if(m[nums[i]].first>1){
               if(abs(m[nums[i]].second-i)<=k)
                   return true;
           }
            m[nums[i]].second=i;
        }
        return false;
    }
};