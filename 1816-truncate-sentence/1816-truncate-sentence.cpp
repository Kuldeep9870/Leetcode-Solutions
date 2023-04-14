class Solution {
public:
    string truncateSentence(string s, int k) {
        string ans;
        for(int i=0;i<s.length()&& k>0;i++){
            if(s[i]==' '){
                k--;
                if(k>0)
                    ans.push_back(' ');
            }
            else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};