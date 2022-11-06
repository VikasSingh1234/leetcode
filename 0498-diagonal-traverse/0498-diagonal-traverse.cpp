class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int dir = 1,i=0,j=0;
        int m = mat.size();
        int n = mat[0].size();
        
        while(i<m && j<n && i>=0 && j>=0){
            if(dir==1){
                ans.push_back(mat[i][j]);
                if(j==n-1){
                    i++;
                    dir = -1;
                }
                else if(i==0){
                    j++;
                    dir=-1;
                }
                else{
                    i--;
                    j++;
                }
            }
            else{
                ans.push_back(mat[i][j]);
                
                if(i==m-1){
                    j++;
                    dir = 1;
                }
                else if(j==0){
                    i++;
                    dir=1;
                }
                else{
                    i++;
                    j--;
                }
            }
        }
        return ans;
    }
};