class Solution {
public:
    int binary(string word,char x){
        int s=0;
        int e=word.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(word[mid]==x)
                return 1;
            else if(int(word[mid])<int(x))
                s=mid+1;
            else
                e=mid-1;
        }
        return 0;
    }
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        int n=words.size();
        for(int i=0;i<n;i++){
            sort(words[i].begin(),words[i].end());
            if(binary(words[i],x))
                ans.push_back(i);
        }
        return ans;
    }
};