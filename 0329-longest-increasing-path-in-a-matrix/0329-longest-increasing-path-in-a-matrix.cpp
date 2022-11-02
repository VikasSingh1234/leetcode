class Solution {
    int delrow[4] = {1,-1,0,0};
    int delcol[4] = {0,0,1,-1};
    int res = 1;
public:
   int dfs(vector<vector<int>>& matrix,int row,int col,vector<vector<int>> &dp){
       
       if(dp[row][col]!=-1){
           return dp[row][col];
       }
       
        int m = matrix.size();
        int n = matrix[0].size();
        int maximum = 1;
        for(int i=0;i<4;i++){
            int newrow = row + delrow[i];
            int newcol = col + delcol[i];
            
            if(newrow>=0 && newcol>=0 && newrow<m && newcol<n){
                if(matrix[newrow][newcol]>matrix[row][col]){
                    int prev =1+ dfs(matrix,newrow,newcol,dp);
                    maximum = max(maximum,prev);
                }
            }
         }
       dp[row][col] = maximum;
       return maximum;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
    
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int res=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int x = dfs(matrix,i,j,dp);
                res = max(res,x);
            }
        }
        return res;
    }
};