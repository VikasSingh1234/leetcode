class Solution {
public:
    void dfs(vector<vector<char>>& grid,int row,int col){
        if(grid[row][col]=='0'){
            return ;
        }
        if(grid[row][col]=='1'){
            grid[row][col] = '0';
        }
        if(row>0){
            dfs(grid,row-1,col);
        }
        if(col>0){
            dfs(grid,row,col-1);
        }
        if(row<grid.size()-1){
            dfs(grid,row+1,col);
        }
        if(col<grid[0].size()-1){
            dfs(grid,row,col+1);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(grid,i,j);
                }
            }
        }
        return count;
    }
};