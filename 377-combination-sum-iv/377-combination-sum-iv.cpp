class Solution {
public:
    int combination(vector<int>& nums, int target,vector<int>& dp){
        if(target==0){
            return 1;
        }
        else if(target<0){
            return 0;
        }
        else if(dp[target]!=-1){
            return dp[target];
        }
        else{
            int result = 0;
            for(int i=0;i<nums.size();i++){
                result+=combination(nums,target-nums[i],dp);
            }
            
            dp[target] = result;
            
            return dp[target];
        }
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        return combination(nums,target,dp);
    }
};