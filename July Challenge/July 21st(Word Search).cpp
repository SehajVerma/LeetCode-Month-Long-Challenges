class Solution {
public:
    bool dfs(vector<vector<char>>& board,string word,int i,int j,int k,vector<vector<bool>>&visited)
    {
        // if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || visited[i][j])
        //     return false;
        if(k==word.size()-1)
            return true;
        // if(board[i][j]!=word[k])
        //     return false;
        visited[i][j]=true;
    if(i+1<board.size() && board[i+1][j]==word[k+1] && !visited[i+1][j] && dfs(board,word,i+1,j,k+1,visited)) return true;
    if(i>0 && board[i-1][j]==word[k+1] && !visited[i-1][j] && dfs(board,word,i-1,j,k+1,visited)) return true;
    if(j+1<board[0].size() && board[i][j+1]==word[k+1] && !visited[i][j+1] && dfs(board,word,i,j+1,k+1,visited)) return true;
    if(j>0 && board[i][j-1]==word[k+1] && !visited[i][j-1] && dfs(board,word,i,j-1,k+1,visited)) return true;
        visited[i][j]=false;
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int r=board.size();
        int c=board[0].size();
        vector<vector<bool>>visited(r,vector<bool>(c,false));
        for(int i=0;i<r;i++)
        {
           for(int j=0;j<c;j++)
           {
               if(board[i][j]==word[0] && dfs(board,word,i,j,0,visited))
                 return true;
           }
        }
        return false;
    }
};
