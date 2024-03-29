class Solution {
public:
    int f(vector<int>& nums,int ind,int prev_ind,vector<vector<int>>& dp){
        if(ind==nums.size()){
            return 0;
        }
        if(dp[ind][prev_ind+1]!=-1){
            return dp[ind][prev_ind+1];
        }
        dp[ind][prev_ind+1] = f(nums,ind+1,prev_ind,dp);
        
        if(prev_ind==-1 || nums[prev_ind]<nums[ind]){
            dp[ind][prev_ind+1] = max(dp[ind][prev_ind+1],1+f(nums,ind+1,ind,dp));
        }
        
        return dp[ind][prev_ind+1];
    }
    
    int lengthOfLIS(vector<int>& nums) {
        // vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));
        // return f(nums,0,-1,dp);
        
        
        // tabulation
        int n = nums.size();
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        for(int ind=n-1;ind>=0;ind--){
            for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--){
                int len = dp[ind+1][prev_ind+1];
        
                if(prev_ind==-1 || nums[prev_ind]<nums[ind]){
                    len = max(len,1+dp[ind+1][ind+1]);
                }
                
                dp[ind][prev_ind+1] = len;
            }
        }
        
        return dp[0][0];
    }
};