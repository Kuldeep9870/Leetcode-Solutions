class Solution {
public:
    string decodeMessage(string key, string message) {
        map<char,char> hash;
        // for(int i=97;i<=122;i++){
        //     m[char(i)]='';
        // }
        int count=0;
        for(char ch:key){
            if(ch!=' ' && hash.find(ch)==hash.end()){
                cout<<ch;
                hash[ch]=char(97+count);
                count++;
            }
        }
        int n=message.size();
        for(int i=0;i<n;i++){
            if(message[i]!=' '){
                int ch=message[i];
                message[i]=hash[ch];
            }
        }
        return message;
    }
};