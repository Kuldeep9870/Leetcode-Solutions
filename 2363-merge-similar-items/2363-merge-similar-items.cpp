class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        //key,sumofWeight
        map<int,int> sum;
        for(int i=0;i<items1.size();i++){
            sum[items1[i][0]]=sum[items1[i][0]]+items1[i][1];
        }
        for(int i=0;i<items2.size();i++){
            sum[items2[i][0]]=sum[items2[i][0]]+items2[i][1];
        }
        vector<vector<int>> ans;
        for(auto i:sum){
            ans.push_back({i.first,i.second});
        }
        return ans;
    }
};