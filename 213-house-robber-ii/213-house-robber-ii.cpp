class Solution {
public:
    int house(vector<int> nums,int idx,vector<vector<int>> &dp,int first){
        if(idx>=nums.size()){
            return 0;
        }
        int pick = 0;
        int notpick = 0;
        if(dp[idx][first]!=-1){
            return dp[idx][first];
        }
        if(idx==0){
            pick = nums[idx] + house(nums,idx+2,dp,1);
            notpick = house(nums,idx+1,dp,first);
        }
        else{
            notpick = house(nums,idx+1,dp,first);
            if(idx==nums.size()-1 && first)
                pick = 0;
            else
                pick = nums[idx] + house(nums,idx+2,dp,first);
        }
        
        dp[idx][first] = max(pick,notpick);
        return dp[idx][first];
    }
    int rob(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(2,-1));
        return house(nums,0,dp,0);
    }
};