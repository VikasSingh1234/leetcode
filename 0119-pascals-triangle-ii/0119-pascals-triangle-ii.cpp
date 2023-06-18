class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> temp;
        long long  curr = 1;
        temp.push_back(1);
        for(int j = 1; j <= rowIndex; j++)
        {
            curr = curr*(rowIndex-j+1)/j;
            temp.push_back(curr);
        }
        
        return temp;
    }
};