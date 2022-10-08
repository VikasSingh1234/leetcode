class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n,0);
        int start,end;
       
        for(int i=0;i<bookings.size();i++){
            start = bookings[i][0];
            end = bookings[i][1];
            
            ans[start-1] += bookings[i][2];
            if(end<n){
                ans[end] -= bookings[i][2];  
            }
        }
        
        for(int i=1;i<n;i++){
                ans[i] += ans[i-1];
            }
        return ans;
    }
};