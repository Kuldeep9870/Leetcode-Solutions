class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<pair<int,int>> zero;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0)
                    zero.push_back({i,j});
            }
        }
        for(int i=0;i<zero.size();i++){
            int r=zero[i].first;
            int c=zero[i].second;
            //col
            int col=0;
            while(col <m)
                matrix[r][col++]=0;

            //row
            int row=0;
            while(row<n)
                matrix[row++][c]=0;
        }
    }
};