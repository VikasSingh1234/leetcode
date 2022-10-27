class Solution {
    
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1){
            return -1;
        }
        
        int delrow[8] = {1,-1,0,0,1,-1,-1,1};
        int delcol[8] = {0,0,1,-1,1,-1,1,-1};
        
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        
        q.push({1,{0,0}});
        dist[0][0] = 1;
        while(!q.empty()){
            int steps = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            
            if(r==n-1 &&  c==n-1){
                return steps;
            }
            
            q.pop();
            
            for(int i=0;i<8;i++){
                int newrow = r+delrow[i];
                int newcol = c+delcol[i];
                
                if(newrow>=0 && newrow<n && newcol>=0 && newcol<n && grid[newrow][newcol]==0){
                    if((steps+1)<dist[newrow][newcol]){
                        dist[newrow][newcol] = steps+1;
                        q.push({dist[newrow][newcol],{newrow,newcol}});
                    }
                }
            }
        }
        
        return -1;
    }
};