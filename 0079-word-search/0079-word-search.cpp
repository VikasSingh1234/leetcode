class Solution {
    int row[4]={1,-1,0,0};
    int col[4]={0,0,1,-1};
public:
    bool dfs(vector<vector<char>>& board, string word,int index,vector<vector<int>> &visited,int x,int y){
        if(index==word.length()-1){
            return true;
        }
        
        visited[x][y] = 1;        
        for(int i = 0;i<4;i++){
            int newrow = x+row[i];
            int newcol = y+col[i];
            
            if(newrow>=0 && newcol>=0 && newrow<board.size() && newcol<board[0].size() && !visited[newrow][newcol] && board[newrow][newcol]==word[index+1]){
                if(dfs(board,word,index+1,visited,newrow,newcol)){
                    return true;
                }
            }
        }
        visited[x][y]=0;
        return false;            
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> visited(board.size(),vector<int>(board[0].size(),0));
        vector<vector<int>> temp(board.size(),vector<int>(board[0].size(),0));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    if(dfs(board,word,0,visited,i,j)){
                        return true;
                    }
                    else
                    {
                        visited=temp;
                    }
                  
                }
            }
        }
        return false;
    }
};