class Solution {
public:
    bool targetsum(vector<int>& nums,int index,int target,vector<vector<int>> &dp){
        int n = nums.size();
        if(target==0){
            return true;
        }
        if(index==n){
            return false;
        }
        
        if(dp[index][target]!=-1){
            return dp[index][target];
        }
        bool notpick = targetsum(nums,index+1,target,dp);
        bool pick = false;
        if(nums[index]<=target){
            pick =  targetsum(nums,index+1,target-nums[index],dp);
        }
        
        return dp[index][target] = pick||notpick;
        
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();

        for(int i=0;i<n;i++){
            sum+=nums[i];
        }

        if(sum%2==1){
            return false;
        }
        else{
            vector<vector<int>> dp(n,vector<int>(sum/2 +1,-1));
            return targetsum(nums,0,sum/2,dp);
        }
    }
};