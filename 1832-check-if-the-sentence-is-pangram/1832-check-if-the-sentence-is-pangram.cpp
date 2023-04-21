class Solution {
public:
    bool checkIfPangram(string sentence) {
        int count[26]={0};
        for(int i=0;i<sentence.length();i++){
            count[sentence[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(count[i]==0)
                return false;
        }
        return true;
        
    }
};