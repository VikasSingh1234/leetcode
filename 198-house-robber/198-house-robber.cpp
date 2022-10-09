class Solution {
public:
    int house(vector<int> nums,int idx,vector<int> &dp){
        if(idx>=nums.size()){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int pick = nums[idx] + house(nums,idx+2,dp);
        int notpick = house(nums,idx+1,dp);
        dp[idx] = max(pick,notpick);
        return dp[idx];
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return house(nums,0,dp);
    }
};