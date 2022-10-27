class Solution {
    
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1){
            return -1;
        }
        
        int delrow[8] = {1,-1,0,0,1,-1,-1,1};
        int delcol[8] = {0,0,1,-1,1,-1,1,-1};
        
        set<pair<int,pair<int,int>>> d;
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        
        d.insert({1,{0,0}});
        dist[0][0] = 1;
        while(!d.empty()){
            auto it  = *(d.begin());
            int steps = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            d.erase(it);
            
            for(int i=0;i<8;i++){
                int newrow = r+delrow[i];
                int newcol = c+delcol[i];
                
                if(newrow>=0 && newrow<n && newcol>=0 && newcol<n && grid[newrow][newcol]==0){
                    if((steps+1)<dist[newrow][newcol]){
                        dist[newrow][newcol] = steps+1;
                        d.insert({dist[newrow][newcol],{newrow,newcol}});
                    }
                }
            }
        }
        
        
        if(dist[n-1][n-1]!=1e9){
            return dist[n-1][n-1];
        }
        else{
            return -1;
        }
        
    }
};