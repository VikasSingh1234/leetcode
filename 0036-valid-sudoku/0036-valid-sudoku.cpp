class Solution {
public:
    bool row(vector<vector<char>>& board){
        int count[10]={0};
        for(int i = 0;i<9;i++){
            for(int z = 1 ;z<10;z++)
                count[z]=0;
            
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    count[board[i][j]-'0']++;
                    if(count[board[i][j]-'0']==2){
                        return false;
                    }
                }
            }
        }
        return true;
    }
    
    bool col(vector<vector<char>>& board){
        int count[10] = {0};
        for(int i = 0;i<9;i++){
            for(int z = 1 ;z<10;z++)
                count[z]=0;
            for(int j=0;j<9;j++){
                if(board[j][i]!='.'){
                    count[board[j][i]-'0']++;
                    if(count[board[j][i]-'0']==2){
                        return false;
                    }
                }
            }
        }
        return true;
    }
    
    bool box(vector<vector<char>>& board){
        int count[10] = {0};
        
        for(int i = 0;i<3;i++){
            for(int j=0;j<3;j++){
                for(int z = 1 ;z<10;z++)
                    count[z]=0;
                for(int k=3*i;k<3*(i+1);k++){
                    for(int l = 3*j;l<3*(j+1);l++){
                        if(board[k][l]!='.'){
                            count[board[k][l]-'0']++;
                            if(count[board[k][l]-'0']==2){
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        return row(board)&&col(board)&&box(board);
    }
};