class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        vector<int> v;
        if(mat[0].size()==1 || mat.size()==1){
            return mat;
        }
        for(int i=0;i<mat.size();i++){
            int row = i;
            int col = 0;
            
            while(row<mat.size() && col<mat[0].size()){
                v.push_back(mat[row][col]);
                row++;
                col++;
            }
            sort(v.begin(),v.end());
            row = i;
            col = 0;
            
            while(row<mat.size() && col<mat[0].size()){
                mat[row][col] = v[0];
                v.erase(v.begin());
                row++;
                col++;
            }
        }
        
        for(int j=1;j<mat[0].size();j++){
            int row = 0;
            int col = j;
            
            while(row<mat.size() && col<mat[0].size()){
                v.push_back(mat[row][col]);
                row++;
                col++;
            }
            sort(v.begin(),v.end());
            row = 0;
            col = j;
            
            while(row<mat.size() && col<mat[0].size()){
                mat[row][col] = v[0];
                v.erase(v.begin());
                row++;
                col++;
            }
            
        }
        
        return mat;
    }
};