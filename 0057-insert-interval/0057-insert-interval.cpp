class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        bool newmerge = false;
        
        for (int i = 0; i < intervals.size(); i++) {
            if (newInterval[0] < intervals[i][0]) {
                intervals.insert(intervals.begin() + i, newInterval);
                newmerge = true;
                break;
            }
        }
        
        if(!newmerge){
            intervals.push_back(newInterval);
        }
        
        vector<int> temp=intervals[0];
        vector<vector<int>> ans;
        
        n = n+1;
        for(int i=1;i<n;i++)
        {
            if(temp[1] >= intervals[i][0])
            {
                  temp[1]=max(temp[1],intervals[i][1]);
            }
            else
            {
                  ans.push_back(temp);
                  temp=intervals[i];
            }
        }
        ans.push_back(temp);
        return ans;
    }
};