class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int i=0;
        // while(i<intervals.size()-1){
        //     if(intervals[i][1] >= intervals[i+1][0]){
        //         intervals[i][1] = max(intervals[i][1],intervals[i+1][1]);
        //         intervals.erase(intervals.begin()+i+1);
        //     }
        //     else{
        //         i++;
        //     }
        // }
        vector<int> temp=intervals[0];
        vector<vector<int>> ans;
        for(int i=1;i<intervals.size();i++)
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