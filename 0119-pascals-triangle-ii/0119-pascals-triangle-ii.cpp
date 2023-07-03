class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        
        //here 0 based indexing so increase rowindex by1
        rowIndex=rowIndex+1;
        
        long value=1;
        ans.push_back(value);
        for(int col=1;col<rowIndex;col++){
            value=value*(rowIndex-col);
            value=value/col;
            
            ans.push_back(value);
        }
        return ans;
    }
};