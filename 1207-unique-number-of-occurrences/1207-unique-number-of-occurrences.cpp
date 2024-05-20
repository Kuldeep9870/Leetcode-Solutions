class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int > m;
        int len[1001]={0};
        for(int i:arr){
            m[i]++;
        }
        for(auto i:m){
            if(len[i.second]==1){
                return false;
            }
            else
                len[i.second]=1;
        }
        return true;
    }
};