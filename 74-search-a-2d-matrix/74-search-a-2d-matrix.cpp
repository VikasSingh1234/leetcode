class Solution {
public:
    bool binary(vector<vector<int>>& matrix,int target,int low,int high,int row){
        if(low <= high){
            int mid = low+(high - low)/2;
            
            if(matrix[row][mid]==target)
                return true;
            else if(matrix[row][mid]>target)
                return binary(matrix,target,low,mid-1,row);
            else
                return binary(matrix,target,mid+1,high,row);
        }
        return false;
    }
        
        
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool res = false;
        for(int i=0;i<matrix.size();i++){
            if(target>=matrix[i][0] && target<=matrix[i][matrix[0].size()-1]){
                res = binary(matrix,target,0,matrix[0].size()-1,i);
                break;
            }
        }
        return res;
    }
};