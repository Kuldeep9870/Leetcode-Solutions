class Solution {
public:
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

void solve(int col,vector<vector<int>>& board,vector<vector<int>>& ans,int n,int& count){
	if(col==n){
		count++;
		return;
	}

	for(int row=0;row<n;row++){
		if(isSafe(row,col,board,n)){
            //safe to place queen
			board[row][col]=1;
			solve(col+1,board,ans,n,count);
			board[row][col]=0;

		}
	}
}
    int totalNQueens(int n) {
    vector<vector<int>> board(n,vector<int>(n,0));
	vector<vector<int>> ans;
        int count=0;

	solve(0,board,ans,n,count);

	return count;
        
    }
};