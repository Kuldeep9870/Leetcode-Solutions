class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int,int> m;
        for(auto i:nums){
            m[i]++;
        }
        int i=1;
        while(1){
            if(m.find(i)!=m.end()){
                i++;
            }
            else{
                return i;
            }
        }  
    }
};