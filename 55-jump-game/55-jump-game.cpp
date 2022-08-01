class Solution {
public:
    
    int jump(vector<int>& nums,int idx,int dp[]){
        
        if(dp[idx]!=-1){
            return dp[idx];
        }
        else if(idx>=nums.size()-1){
            return 1;
        }
        else if(nums[idx]==0){
            return 0;
        }
        else{
            for(int i=1;i<=nums[idx];i++){
                dp[idx+i] = jump(nums,idx+i,dp);
                if(dp[idx+i]==1){
                    return 1;
                }
            }
        }
        return 0;
    }
    
    bool canJump(vector<int>& nums) {
        int  dp[nums.size()];
        for(int i=0;i<nums.size();i++){
            dp[i]=-1;
        }
        
        dp[0] = jump(nums,0,dp);
        if(dp[0]==1){
            return true;
        }
        else{
            return false;
        }
        
    }
};