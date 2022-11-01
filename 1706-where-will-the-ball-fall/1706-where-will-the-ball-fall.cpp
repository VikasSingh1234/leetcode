class Solution {
public:
    int check(vector<vector<int>> grid,int i,int j){
        int m = grid.size();
        int n = grid[0].size();
        
        while(i<m && j<n && i>=0 && j>=0){
            if(grid[i][j]==1){
                if(j+1<n){
                    if(grid[i][j+1]==1){
                        i++;
                        j++;
                    }
                    else{
                        return -1;
                    }
                }
                else{
                    return -1;
                }
            }
            else{
                if(j-1>=0){
                    if(grid[i][j-1]==-1){
                        i++;
                        j--;
                    }
                    else{
                        return -1;
                    }
                }
                else{
                    return -1;
                }
            }
        }
        if(i==m){
            return j;
        }
        
        return -1;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> ans;
        for(int j=0;j<n;j++){
            ans.push_back(check(grid,0,j));
        }
        return ans;
    }
};