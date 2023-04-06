class Solution {
public:
    
    bool helper(vector<vector<int>> &grid,vector<vector<int>> &visited,int i,int j,int m,int n){
        if(i<0 || j<0 || j>=n || i>=m){
            return false;
        }
        if(visited[i][j] || grid[i][j]){
            return true;
        }    
        else{
            int x[4] = {0,1,0,-1};
            int y[4] = {-1,0,1,0};
            visited[i][j] = 1;
            bool dir = true;
            for(int dx = 0;dx<4;dx++){
                int deltax = i+x[dx];
                int deltay = j+y[dx];
                        
                bool l = helper(grid,visited,deltax,deltay,m,n);
                if(l==false){
                    dir = false;
                }
            }
            return dir;
            }
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<vector<int>> visited(m,vector<int>(n,0)); 
        
        for(int i=0;i<m;i++){
            
            for(int j=0;j<n;j++){
                if(grid[i][j]==0 && visited[i][j]==0){
                    if(helper(grid,visited,i,j,m,n)){
                        ans++;
                    }
                }    
            }
            
        }
        return ans;
    }
};