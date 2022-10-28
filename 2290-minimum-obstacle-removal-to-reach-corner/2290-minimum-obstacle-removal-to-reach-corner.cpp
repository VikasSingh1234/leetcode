class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int delrow[4] = {1,-1,0,0};
        int delcol[4] = {0,0,1,-1};
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        vector<vector<int>> dist(m,vector<int>(n,1e9));
        if(grid[0][0]==1){
            q.push({1,{0,0}});
            dist[0][0] = 1;
        }
        else{
            q.push({0,{0,0}});
            dist[0][0] = 0;
        }
        
        while(!q.empty()){
            int steps = q.top().first;
            int r = q.top().second.first;
            int c = q.top().second.second;
            
            if(r==m-1 &&  c==n-1){
                return steps;
            }
            
            q.pop();
            
            for(int i=0;i<4;i++){
                int newrow = r+delrow[i];
                int newcol = c+delcol[i];
                
                if(newrow>=0 && newrow<m && newcol>=0 && newcol<n){
                    if(grid[newrow][newcol]==0){
                        if((steps)<dist[newrow][newcol]){
                            dist[newrow][newcol] = steps;
                            q.push({dist[newrow][newcol],{newrow,newcol}});
                        }
                    }
                    else{
                        if((steps+1)<dist[newrow][newcol]){
                            dist[newrow][newcol] = steps+1;
                            q.push({dist[newrow][newcol],{newrow,newcol}});
                        }
                    }
                }
            }
        }
        return 0;
    }
};