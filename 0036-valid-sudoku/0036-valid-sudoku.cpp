class Solution {
public:
    bool isValid(int row,int col,vector<vector<char>>& board,int val){
    int n=board[0].size();

    for(int i=0;i<n;i++){
        //row check
        if(board[i][col]==val)
        return false;

        //col check
        if(board[row][i]==val)
        return false;

        //3X3 matrix check
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==val)
        return false;
    }
    return true;
}
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board[0].size();
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                bool check=true;
                char val=board[row][col];
                board[row][col]='#';
                if(val>='1' && val<='9'){
                    //check value at (row,col)
                    
                    check=isValid(row,col,board,val);
                    //cout<<val<<"->"<<check;
                    if(check==false)
                        return false;
                }
                board[row][col]=val;
            }
        }
        return true;
        
    }
};