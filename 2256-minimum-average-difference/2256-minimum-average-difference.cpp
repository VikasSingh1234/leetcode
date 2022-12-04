class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long int total = 0;
        long long int prev = 0;
        long long int avg = INT_MAX;
        int ans=0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            total+=nums[i];
        }
        
        for(int i=0;i<n-1;i++){
            prev +=nums[i];
            total-=nums[i];
            long long int diff = abs((prev/(i+1))-(total/(n-i-1)));
            if(diff<avg){
                avg = diff;
                ans = i;
            }
        }
        
        prev+=nums[n-1];
        
        if(avg>prev/n){
            ans = n-1;
        }
        
        return ans;
    }
};