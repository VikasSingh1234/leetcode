class Solution {
public:
    int TargetSum(int i,int n,vector<int>& nums, int target,vector<vector<int>> &dp){
        
        if(i==n-1){
            if(target==0 && nums[i]==0) return 2;
            if(target==0 || target==nums[i]) return 1;
            return 0;
        }
        
        if(dp[i][target]!=-1) return dp[i][target];
        int nottake = TargetSum(i+1,n,nums,target,dp);
        int take = 0;
        
        if(nums[i]<=target){
            take = TargetSum(i+1,n,nums,target-nums[i],dp);
        }
        // int plus  = TargetSum(i+1,n,nums,target+nums[i]);
        // int minus = TargetSum(i+1,n,nums,target-nums[i]);
        
        // return plus+minus;
        return dp[i][target]=take+nottake;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int sum = 0;
        for(auto x:nums) sum+=x;
        
        if(sum-target<0) return 0;
        if((sum-target)%2) return 0;
        
        int newtarget = (sum-target)/2;
        
        vector<vector<int>> dp(nums.size()+1,vector<int>(newtarget+1,-1));
        
        return TargetSum(0,nums.size(),nums,newtarget,dp);
    }
};