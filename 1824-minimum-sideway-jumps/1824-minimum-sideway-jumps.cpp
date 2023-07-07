class Solution {
public:
    int f(vector<int>& obstacles,int index,int n,int lane,vector<vector<int>> &dp){
        if(index==n-1){
            return 0;
        }
        
        if(dp[index][lane]!=-1){
            return dp[index][lane];
        }
        
        int ans = INT_MAX;
        
        if(obstacles[index+1]!=lane){
            return f(obstacles,index+1,n,lane,dp);
        }
        else{
            for(int i=1;i<=3;i++){
                if(i!=lane && obstacles[index]!=i){
                    ans = min(ans,1+f(obstacles,index,n,i,dp));
                }
                dp[index][lane] = ans;
            }
            return dp[index][lane];
        }
        
        
    }
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<vector<int>> dp(n,vector<int>(4,-1));
        return f(obstacles,0,n,2,dp);
    }
};