class Solution {
public:
    bool helper(vector<int> time,int totalTrips,long long int m){
        long long int count = 0;
        int n = time.size();
        
        for(int i=0;i<n;i++){
            count += m/time[i];
        }
        if(count>=totalTrips)
                return true;
        return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        int max_ele = 0;
        int n = time.size();
        
        for(int i=0;i<n;i++){
            max_ele = max(max_ele,time[i]);    
        }
        
        long long int low = 1,high = totalTrips;
        high = high*max_ele;
        
        long long ans = high;
        
        while(low<high){
            long long int mid = low+(high-low)/2;
            
            if(helper(time,totalTrips,mid)){
                ans = min(ans,mid);
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        
        return ans;
    }
};