//comparater used for sorting
//it take pair then compare then sort
bool compare(pair<int,char> p1,pair<int,char> p2){
        return p1.first>p2.first; 
    }
class Solution {
public:
    
    string frequencySort(string s) {
        unordered_map<char,int> m;
        for(auto i:s){
            m[i]++;
        }
        //char,freq -> frq,char then sort
        vector<pair<int,char>> v;
        for(auto i:m){
            v.push_back({i.second,i.first});
        }

        sort(v.begin(),v.end(),compare);
        string ans;
        // for(auto i:v){
        //     ans.push_back(i.second);
        // }
        for(int i=0;i<v.size();i++){
            while(v[i].first--){
                ans.push_back(v[i].second);
            }
        }
        return ans;
    }
};