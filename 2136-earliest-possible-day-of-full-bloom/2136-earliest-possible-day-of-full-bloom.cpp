class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int grow = 0;
        int plant;
        int n = plantTime.size();
        vector<pair<int, int>> v;
        
        for (auto i = 0; i < n; ++i)
            v.push_back({growTime[i], plantTime[i]});
        
        sort(v.begin(), v.end());
        
        for(int i=0;i<n;i++){
            plant = v[i].second;
            grow=max(grow,v[i].first)+plant;  
        }
            
        return grow;
    }
};