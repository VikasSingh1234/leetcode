class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
    
        for(int i=1;i<=numRows;i++){
            vector<int> temp;
            int curr = 1;
            temp.push_back(1);
            for(int j = 1; j < i; j++)
            {
                curr = curr*(i-j)/j;
                temp.push_back(curr);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};