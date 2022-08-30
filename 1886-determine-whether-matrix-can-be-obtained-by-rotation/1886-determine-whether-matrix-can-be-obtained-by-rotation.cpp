class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        
        int i =4;
        if(mat==target)
            return true;
        while(--i){
            for(int i=0;i<mat.size();i++){
            for(int j=i+1;j<mat.size();j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
        
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat.size()/2;j++){
                swap(mat[i][j],mat[i][mat.size()-j-1]);
            }
        }
            if(mat==target)
                return true;
        }
        return false;
    }
};