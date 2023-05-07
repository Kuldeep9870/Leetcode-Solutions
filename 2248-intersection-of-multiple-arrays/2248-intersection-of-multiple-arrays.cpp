class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        map<int,int> m;
        for(auto i:nums){
            for(auto j:i){
                m[j]++;
            }
        }
        int n=nums.size();
        vector<int> ans;
        for(auto i:m){
            if(i.second==n)
                ans.push_back(i.first);
        }
        return ans;
    }
};