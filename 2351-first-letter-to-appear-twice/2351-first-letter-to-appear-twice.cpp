class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char,int> m;
        char ch;
        for(auto i:s){
            m[i]++;
            if(m[i]>=2){
                ch=i;
                break;
            }
        }
        return ch;
    }
};