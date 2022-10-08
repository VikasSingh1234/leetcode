class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        int ans=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                dp[i] = 1 + dp[i-1];
                if(ans<dp[i]){
                    ans = dp[i];
                }
            }
        }
        return ans;
    }
};