class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string,int> mpp;
        int n = grid.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            string row;
            for(int j = 0;j<n;j++){
                row+=to_string(grid[i][j])+"0";
            }
            mpp[row]++;
        }
        
        for(int i=0;i<n;i++){
            string col;
            for(int j = 0;j<n;j++){
                col+=to_string(grid[j][i])+"0";
            }
            
            if(mpp.find(col)!=mpp.end()){
                ans += mpp[col];
                
            }
            
        }
        
        return ans;
    }
};