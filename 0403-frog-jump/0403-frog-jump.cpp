class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int , unordered_set<int>> mpp;
        mpp[stones[0] + 1] = {1}; 
        int n = stones.size();
        
        for(int i = 1 ; i < n ; ++i){ 
            int pos = stones[i];  
            for(auto it : mpp[pos]){   
                mpp[pos + it].insert(it);  
                mpp[pos + it + 1].insert(it + 1);
                mpp[pos + it - 1].insert(it - 1);
            }
        }
        return mpp[stones[n-1]].size() != 0; 
    }
};