class Solution {
public:
    bool checkVowel(char s){
        if(s=='a'|| s=='e' || s=='i'|| s=='o'|| s=='u')
            return true;
        else
            return false;
    }
    int vowelStrings(vector<string>& words, int left, int right) {
        int count=0;
        for(int i=left;i<=right;i++){
            string s=words[i];
            if(checkVowel(s[0]) && checkVowel(s[s.length()-1]))
                count++;
        }
        return count;
    }
};