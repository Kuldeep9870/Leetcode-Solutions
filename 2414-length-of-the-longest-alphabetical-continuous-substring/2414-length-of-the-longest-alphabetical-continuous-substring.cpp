class Solution {
public:
    int longestContinuousSubstring(string s) {
        int count = 1;
        int ans=1;
        for(int i=1;i<s.length();i++){
            if(s[i-1]-s[i]==-1)
                count++;
            else
                count=1;
            
            ans=max(ans,count);
        }
        
        return ans;
    }
};