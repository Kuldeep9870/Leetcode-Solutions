class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        
        for(auto i:nums1){
            if(m[i]==0)
                m[i]=1;
        }
        
        for(auto i:nums2){
            if(m[i]==0)
                m[i]=2;
            else if(m[i]==1)
                m[i]=3;
        }
        vector<int> ans;
        for(auto i:m){
            if(i.second==3)
                ans.push_back(i.first);
        }
        return ans;
    }
};