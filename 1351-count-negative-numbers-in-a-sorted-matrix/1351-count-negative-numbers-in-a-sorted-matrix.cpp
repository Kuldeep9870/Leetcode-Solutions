class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count=0;
        for(auto i:grid){
            for(int j=i.size()-1;j>=0;j--){
                if(i[j]>=0)
                    break;
                
                count++;
            }
        }
        return count;
    }
};