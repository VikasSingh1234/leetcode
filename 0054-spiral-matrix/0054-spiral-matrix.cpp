class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int left = 0,right = matrix[0].size()-1;
        int down = matrix.size()-1,up = 0;
        int dir = 0,i;
        while(res.size()<matrix.size()*matrix[0].size()){
            if(dir==0){
                for(i=left;i<=right;i++){
                    res.push_back(matrix[up][i]);
                }
                up++;
                dir = (dir+1)%4;
                continue;
            }
            else if(dir==1){
                for(i=up;i<=down;i++){
                    res.push_back(matrix[i][right]);
                }
                right--;
                dir = (dir+1)%4;
                continue;
            }
            else if(dir==2){
                for(i=right;i>=left;i--){
                    res.push_back(matrix[down][i]);
                }
                down--;
                dir = (dir+1)%4;
                continue;
            }
            else if(dir==3){
                for(i=down;i>=up;i--){
                    res.push_back(matrix[i][left]);
                }
                left++;
                dir = (dir+1)%4;
                continue;
            }
        }
        return res;
    }
};