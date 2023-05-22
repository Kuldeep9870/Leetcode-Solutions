class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(auto i:nums)
            m[i]++;
        
        vector<pair<int,int>> top;
        vector<int> ans;
        for(auto i:m){
            //{frequency,element}
            top.push_back({i.second,i.first});
        }
        
        sort(top.begin(),top.end());
        /*
        mapping is done in top like {freq,element}={1<-3},{2<-2},{3<-1}
        */
        
        //accessing from back of top list
        for(auto i=top.rbegin();i!=top.rend() && k!=0 ;i++){
            ans.push_back(i->second);
            k--;
        }
        return ans;
    }
};