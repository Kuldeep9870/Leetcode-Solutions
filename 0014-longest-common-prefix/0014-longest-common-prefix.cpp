#include <algorithm> 
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int n=strs.size();
        int minSize =INT_MAX;
        for(int i=0;i<n;i++){
            int size =strs[i].length();
            minSize = min(minSize,size);
        }
        for(int i=0;i<minSize;i++){
            int match=true;
            char ch=strs[0][i];
            for(int j=1;j<n;j++){
                if(strs[j][i]!= ch){
                    match=false;
                    break;
                }
            }
            if(match){
                ans+=ch;
            }
            else{
                return ans;
            }
        }
        return ans;
    }
};