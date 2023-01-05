class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        
        int n = intervals.size();
        int end = INT_MIN;  
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(intervals[i][0] < end){
                ans++;
                if(end>intervals[i][1]){
                    end = intervals[i][1];
                }
            }
            else{
                end = intervals[i][1];
            }
        }
        return ans;
    }
};