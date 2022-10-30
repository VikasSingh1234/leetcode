class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int delrow[4] = {1,-1,0,0};
        int delcol[4] = {0,0,1,-1};
        
        priority_queue<pair<pair<int,int>,pair<int,int>>,vector<pair<pair<int,int>,pair<int,int>>>,greater<pair<pair<int,int>,pair<int,int>>>> q;
        vector<vector<pair<int,int>>> dist(m,vector<pair<int,int>>(n,{1e9,1e9}));
        
        if(grid[0][0]==1){
            q.push({{0,1},{0,0}});
            dist[0][0] = {0,1};
        }
        else{
            q.push({{0,0},{0,0}});
            dist[0][0] = {0,0};
        }
        
        while(!q.empty()){
            int d = q.top().first.first;
            int steps = q.top().first.second;
            int r = q.top().second.first;
            int c = q.top().second.second;
            
            if(r==m-1 &&  c==n-1){
                return d;
            }
            
            q.pop();
            
            for(int i=0;i<4;i++){
                int newrow = r+delrow[i];
                int newcol = c+delcol[i];
                
                if(newrow>=0 && newrow<m && newcol>=0 && newcol<n){
                    if(grid[newrow][newcol]==0){
                        if(dist[newrow][newcol].first>d+1){
                            dist[newrow][newcol].first=d+1;
                            q.push({{d+1,steps},{newrow,newcol}});
                        }
                        else if(steps<dist[newrow][newcol].second){
                            dist[newrow][newcol].first=d+1;
                            dist[newrow][newcol].second=steps;
                            q.push({{d+1,steps},{newrow,newcol}});
                        }
                    }
                    else{
                        if(steps+1<=k && dist[newrow][newcol].first>d+1){
                            dist[newrow][newcol].second = steps+1;
                            dist[newrow][newcol].first=d+1;
                            q.push({{d+1,steps+1},{newrow,newcol}});
                        }
                    }
                }
            }
        }
        return -1;
    }
};