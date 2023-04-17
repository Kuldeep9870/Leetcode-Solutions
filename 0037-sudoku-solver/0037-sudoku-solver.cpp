class Solution {
public:
    bool isSafe(int row,int col,vector<vector<char>>& board,char val){
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
    bool solve(vector<vector<char>>& board){
        int n=board[0].size();
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(board[row][col]=='.'){
                    //cell empty
                    for(char val='1';val<='9';val++){
                        if(isSafe(row,col,board,val)){
                            board[row][col]=val;

                            //recursive call to check whether after inserting val
                            //sudoku can be solved or not
                            bool possible=solve(board);
                            if(possible)
                            return true;
                            else{
                                board[row][col]='.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};