class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n));
        
        int left = 0,right = n-1;
        int down = n-1,up = 0;
        int ele = 1;
        int dir = 0,i;
        while(ele<=n*n){
            if(dir==0){
                for(i=left;i<=right;i++){
                    matrix[up][i] = ele++;
                }
                up++;
                dir = (dir+1)%4;
                continue;
            }
            else if(dir==1){
                for(i=up;i<=down;i++){
                    matrix[i][right]= ele++;
                }
                right--;
                dir = (dir+1)%4;
                continue;
            }
            else if(dir==2){
                for(i=right;i>=left;i--){
                    matrix[down][i]= ele++;;
                }
                down--;
                dir = (dir+1)%4;
                continue;
            }
            else if(dir==3){
                for(i=down;i>=up;i--){
                    matrix[i][left]= ele++;;
                }
                left++;
                dir = (dir+1)%4;
                continue;
            }
        }
        return matrix;
    }
};