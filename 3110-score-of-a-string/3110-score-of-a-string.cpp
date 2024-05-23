class Solution {
public:
    int scoreOfString(string s) {
        int n=s.length();
        int val1=int(s[0]);
        
        int score=0;
        for(int i=1;i<n;i++){
            int val2=int(s[i]);
            score=score + abs(val1-val2);
            val1=val2;
        }
        return score;
        
    }
};