class Solution {
public:
    string replaceDigits(string s) {
        int n=s.length();
        
        for(int i=0;i<n;i=i+2){
            s[i+1]=s[i]+(s[i+1]-'0');
        }
        return s;
    }
};