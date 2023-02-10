class Solution {
    int delrow[4] = {1,-1,0,0};
    int delcol[4] = {0,0,1,-1};
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = -1;
        vector<vector<int>> visited(n,vector<int>(m));
        queue<pair<int,int>> q;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                visited[i][j] = grid[i][j];
                if(grid[i][j]){
                    q.push({i, j});
                }
            }
        }
        
        while(!q.empty()){
            int s = q.size();
            
            while(s--){
                auto it = q.front();
                q.pop();

                int row = it.first;
                int col = it.second;
                
                for(int i=0;i<4;i++){
                    int r = row+delrow[i];
                    int c = col+delcol[i];

                    if(r>=0 && c>=0 && r<n && c<m){
                        if(!visited[r][c]){
                            q.push({r,c});
                            visited[r][c] = 1;
                        }
                    }
                }
            }
            ans++;
        }
        
        if(ans==0)
            return -1;
        return ans;
        
    }
};