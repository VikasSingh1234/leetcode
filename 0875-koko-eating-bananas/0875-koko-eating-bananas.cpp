class Solution {
public:
    bool helper(vector<int> piles,int h,long long int m){
        long long int count = 0;
        int n = piles.size();
        
        for(int i=0;i<n;i++){
            if(piles[i]%m==0)
                count += piles[i]/m;
            else
                count += piles[i]/m + 1;
        }
        
        if(count<=h)
                return true;
        return false;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int max_ele = 0;
        int n = piles.size();
        
        for(int i=0;i<n;i++){
            max_ele = max(max_ele,piles[i]);    
        }
        
        int low = 1;
        int high = max_ele;
        
        long long ans = high;
        
        while(low<high){
            long long int mid = low+(high-low)/2;
            
            if(helper(piles,h,mid)){
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