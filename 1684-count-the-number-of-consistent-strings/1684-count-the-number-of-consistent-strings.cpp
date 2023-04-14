class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,bool> m;
        int count=0;
        for(auto i:allowed){
            m[i]=true;
        }
        for(int i=0;i<words.size();i++){
            string s=words[i];
            bool ans=true;
            for(int j=0;j<s.length();j++){
                if(m.find(s[j])==m.end()){
                    ans=false;
                    break;
                }
            }
            if(ans==true){
                //cout<<i<<" ";
                count++;
            }
        }
        return count;
    }
};