class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> m;
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
        vector<int> first;
        vector<int> second;
        for(auto i:m){
            if(i.second==1)
                first.push_back(i.first);
            else if(i.second==2)
                second.push_back(i.first);
        }
        return {first,second};
    }
};