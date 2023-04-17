class Solution {
public:
        void copyanswer(vector<vector<int>>& board,vector<vector<string>>& ans,int n){
        vector<string> data;
        string temp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==1)
                    temp.push_back('Q');
                else
                    temp.push_back('.');
            }
            data.push_back(temp);
            temp.clear();
        }
        
        ans.push_back(data);
    }
    bool isSafe(int row,int col,vector<vector<int>>& board,int n){
        int x=row;
        int y=col;

        //for row check
        while(y>=0){
            if(board[x][y]==1)
            return false;

            y--;
        }
        x=row;
        y=col;
        //for upper diagonal check
        while(x>=0 && y>=0){
            if(board[x][y]==1)
            return false;

            x--;
            y--;
        }

        //forlower diagonal check
        x=row;
        y=col;
        while(x<n&& y>=0){
            if(board[x][y]==1)
            return false;

            x++;
            y--;
        }
        return true;
    }

    void solve(int col,vector<vector<int>>& board,vector<vector<string>>& ans,int n){
        if(col==n){
            copyanswer(board,ans,n);
            return;
        }

        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                //safe to place the queen
                board[row][col]=1;
                solve(col+1,board,ans,n);
                board[row][col]=0;

            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> board(n,vector<int>(n,0));
	    vector<vector<string>> ans;

	    solve(0,board,ans,n);

	    return ans;
    }
};