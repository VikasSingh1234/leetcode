class Solution {
public:
    bool isPossible(vector<int>& weights, int days,int mid){
        int count = 1;
        int n = weights.size();
        int wt = 0;
        
        for(int i=0;i<n;i++){
            if(wt+weights[i]<=mid){
                wt+=weights[i];
            }
            else{
                count++;
                if(count>days || weights[i]>mid){
                    return false;
                }
                wt = weights[i];
            }
        }
        
        return true;  
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        int low = 0;
    
        int ans = INT_MAX;
        int n = weights.size();
        
        for(int i=0;i<n;i++) 
            sum += weights[i];
        
        int high = sum;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            
            if(isPossible(weights,days,mid)){
                ans = min(ans,mid);
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        
        return ans;
    }
};