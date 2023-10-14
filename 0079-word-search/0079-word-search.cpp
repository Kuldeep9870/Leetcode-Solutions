class Solution {
public:
    bool find(int row,int col,vector<vector<char>>& board,vector<vector<bool>>& vis, string word,int count){
        if(count==word.length())
            return true;
        
        int n=board.size();
        int m=board[0].size();
    
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        
        for(int i=0;i<4;i++){
            int nrow=row +dx[i];
            int ncol=col+dy[i];
            if(nrow<n && nrow>=0 && ncol>=0 && ncol<m && !vis[nrow][ncol] &&                                    board[nrow][ncol]==word[count]){
                    vis[nrow][ncol]=1;
                    bool ans=find(nrow,ncol,board,vis,word,count+1);
                    if(ans)
                        return true;
                    vis[nrow][ncol]=0;
                }
        }
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]==word[0]){
                    vis[i][j]=1;
                    bool ans=find(i,j,board,vis,word,1);
                    if(ans)
                        return true;
                    vis[i][j]=0;
                }
            }
        }
        return false;
    }
};