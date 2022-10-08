class Solution {
    int helper(vector<int>& prices,int buy,int index,vector<vector<int>> &dp)
    {
        if(index>=prices.size())
            return 0;
        if(dp[index][buy]!=-1)
            return dp[index][buy];
        int notpick=helper(prices,buy,index+1,dp);
        int pick=INT_MIN;
        if(buy)
        {
            pick=-prices[index]+helper(prices,0,index+1,dp);
        }
        else
        {
            pick=+prices[index]+helper(prices,1,index+2,dp);
        }
        return dp[index][buy]=max(pick,notpick);
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return helper(prices,1,0,dp);
    }
};