class Solution {
public:
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        
        vector<vector<int>> visited(n,vector<int>(m,0));
        visited[entrance[0]][entrance[1]] = 1;
        
        queue<pair<int,pair<int,int>>> q;
        
        q.push({0,{entrance[0],entrance[1]}});
    
        while(!q.empty()){
            int delrow[4] = {1,-1,0,0};
            int delcol[4] = {0,0,1,-1};
            
            auto it = q.front();
            q.pop();
            int r = it.second.first;
            int c = it.second.second;
            int d = it.first;
            
            for(int i = 0;i<4;i++){
                int nrow = r+delrow[i];
                int ncol = c+delcol[i];
                
                if(nrow>=0 &&  nrow<n &&ncol>=0 && ncol<m && maze[nrow][ncol]!='+' &&!visited[nrow][ncol]){
                    if(nrow==0 || ncol==0 || nrow==n-1 || ncol==m-1){
                        return d+1;
                    }
                    else{
                        visited[nrow][ncol] = 1;
                        q.push({d+1,{nrow,ncol}});
                    }
                }
            }
        }
        
        return -1;
    }
};