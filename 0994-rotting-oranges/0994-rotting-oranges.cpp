class Solution {
public:
    bool check(vector<vector<int>> grid,vector<vector<int>> visited){
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]!=0 && visited[i][j]==0){
                    return false;
                }
            }
        }
        return true;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    visited[i][j] = 1;
                }
            }
        }
        
        
         int row[]={-1,1,0,0};
        int col[]={0,0,-1,1};
        int mintime=0;
        int m = grid.size();
        int n = grid[0].size();
        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int time = q.front().second;
            mintime = time;
            q.pop();
            
            for(int r=0;r<4;r++){
                int newrow = i+row[r];
                int newcol = j+col[r];
                
                if(newrow>=0 && newrow<m && newcol>=0 && newcol<n && !visited[newrow][newcol] && grid[newrow][newcol]==1){
                    q.push({{newrow,newcol},time+1});
                    visited[newrow][newcol] = 1;
                }
            }   
        }
        if(check(grid,visited))
            return mintime;
        else
            return -1;
    }
};