class Solution {
    int row[4] = {-1,1,0,0};
    int col[4] = {0,0,1,-1};
public:
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> resultMatrix(m,vector<int>(n));
        vector<vector<int>> visited(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    visited[i][j] = 1;
                    resultMatrix[i][j] = 0;
                }
            }
        }
        
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int distance = q.front().second;
            
            q.pop();
            
            for(int idx=0;idx<4;idx++){
                int newrow = x+row[idx];
                int newcol = y+col[idx];
                
                if(newrow>=0 && newrow<m && newcol>=0 && newcol<n && !visited[newrow][newcol]){
                    visited[newrow][newcol] = 1;
                    q.push({{newrow,newcol},distance+1});
                    resultMatrix[newrow][newcol] = distance+1;
                }
            }
        }
        
        return resultMatrix;
    }
};