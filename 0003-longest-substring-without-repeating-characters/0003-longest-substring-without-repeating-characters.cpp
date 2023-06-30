class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int i,j;
        i=j=0;
        int ans=0;
        
        while(j<s.length()){
            m[s[j]]++;
            if(m.size()==(j-i+1)){ //equal size to window
                ans=max(ans,j-i+1);
            }
            else if(m.size()<j-i+1){
                
                while(m.size()<j-i+1){
                    m[s[i]]--;
                    if(m[s[i]]==0){
                        m.erase(s[i]);
                    }
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};