class Solution {
public:
    vector<int> generateRow(int row){
        vector<int> rowAns;
        int ans=1;
        rowAns.push_back(ans);
        for(int col=1;col<row;col++){
            ans=ans*(row-col);
            ans=ans/col;
            
            rowAns.push_back(ans);
        }
        return rowAns;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++){
            vector<int> temp=generateRow(i);
            
            ans.push_back(temp);
        }
        return ans;
    }
};