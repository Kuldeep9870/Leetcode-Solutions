class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        
        //using two pointer approach if all element of s is present in same relative order in t then it is a subsequence
        int j=0;
        int n=t.length();
        
        for(int i=0;i<n;i++)
        {
            if(s[j]==t[i])
                j++;
        }
        
        return (j==s.length());
        
        
    }
};