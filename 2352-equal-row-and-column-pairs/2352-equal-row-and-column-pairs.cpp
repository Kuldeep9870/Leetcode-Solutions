class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> col;
        for(int i=0;i<n;i++){
            vector<int> v;
            for(int j=0;j<n;j++){
                v.push_back(grid[j][i]);
            }
            col.push_back(v);
        }
        int count=0;
        for(auto i:grid){
            for(auto j:col){
                if(i==j)
                    count++;
            }
        }
        return count;
    }
};