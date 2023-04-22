class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,bool> m;
        for(auto i:jewels){
            m[i]=true;
        }
        int count=0;
        for(auto i:stones){
            if(m.find(i)!=m.end())
                count++;
        }
        return count;
        
    }
};