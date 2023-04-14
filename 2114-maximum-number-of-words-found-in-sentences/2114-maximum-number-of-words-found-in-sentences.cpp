class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxcount=0;
        for(int i=0;i<sentences.size();i++){
            string s=sentences[i];
            int count=0;
            for(int j=0;j<s.length();j++){
                if(s[j]==' ')
                    count++;
            }
            count++;
            maxcount=max(count,maxcount);
        }
        return maxcount;
    }
};