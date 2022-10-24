class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> res = board;
        int neighbour = 0;
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<board.size();i++){
            
            for(int j = 0;j<board[0].size();j++){
                neighbour = 0;
                if(j+1<n){
                    if(board[i][j+1]){
                        neighbour++;
                    }
                }
                
                if(j-1>=0){
                    if(board[i][j-1]){
                        neighbour++;
                    }
                }
                
                
                
                if(i-1>=0){
                    if(board[i-1][j]){
                        neighbour++;
                    }
                    
                    if(j-1>=0){
                        if(board[i-1][j-1]){
                            neighbour++;
                        }
                        
                    }
                    if(j+1<n){
                        if(board[i-1][j+1]){
                            neighbour++;
                        }
                    }
                }
                if(i+1<m){
                    if(board[i+1][j]){
                        neighbour++;
                    }
                    if(j-1>=0){
                        if(board[i+1][j-1]){
                            neighbour++;
                        }
                    }
                    if(j+1<n){
                        if(board[i+1][j+1]){
                            neighbour++;
                        }
                    }
                }
                
                if(neighbour<2){
                    res[i][j] = 0;
                }
                else if(neighbour>3){
                    res[i][j]=0;
                }
                else if(neighbour==3 && board[i][j]==0){
                    res[i][j]=1;
                }
            }
        }
        board=res;
    }
};