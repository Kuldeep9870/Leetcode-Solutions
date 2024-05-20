class Solution {
public:
    void reverse(string& s) {
        int start = 0;
        int end =s.length()-1;
        while(start<=end){
            //cout<<s[start]<<"-"<<s[end];
            swap(s[start],s[end]);
            start++;
            end--;
        }
    }
    string reverseWords(string s) {
        string ans="";
        string word="";
        for(auto i:s){
            
            if(i!=' '){
                word+=i;
            }
            else if(i==' '){
                reverse(word);
                ans+=word;
                word="";
                ans+=" ";
            }
        }
        //for last word
        reverse(word);
        ans+=word;
        return ans;
    }
};