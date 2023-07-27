class Solution {
public:
    string removeOuterParentheses(string s) {
        int count=0;
        int n=s.length();
        int first=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                count++;
            }
            else if(count ==1 && s[i]==')'){
                count--;
                s[i]='0';
                s[first]='0';
                first=-1;
            }
            else if(s[i]==')'){
                count--;
            }
            
            if(first==-1 && count==1)
                first=i;
        }
        
        string ans="";
        for(char& c:s){
            if(c!='0')
                ans+=c;
        }
        return ans;
    }
};