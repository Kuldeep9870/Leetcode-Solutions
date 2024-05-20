class Solution {
public:
    void reverseString(string& s , int start, int end) {
        while(start<=end){
            cout<<s[start]<<"-"<<s[end];
            swap(s[start],s[end]);
            start++;
            end--;
        }
        cout<<endl;
    }
    string reverseStr(string s, int k) {
        int len=s.length() -1;
        
        for(int i=0 ;i<=len;i=i+2*k){
            if(i+k<=len){
                cout<<i<<" "<<i+k-1<<":";
                reverseString(s,i,i+k-1);
            }
            else if(len- i +1 <=k){
                reverseString(s,i,len);
            }
        }
        return s;
    }
};