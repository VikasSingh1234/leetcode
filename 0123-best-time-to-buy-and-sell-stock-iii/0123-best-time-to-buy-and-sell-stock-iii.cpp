class Solution {
public:
    int buy(vector<int>& prices,int index,int ntob,int status,vector<vector<vector<int>>> &dp){
        if(index==prices.size())
            return 0;
        if(dp[index][ntob][status]!=-1)
            return dp[index][ntob][status];
        if(status){
            if(index==prices.size()-1)
            {
                return dp[index][ntob][status]=prices[index];
            }
            
            int notsell = buy(prices,index+1,ntob,status,dp);
            int sell = prices[index]+buy(prices,index+1,ntob,0,dp);
            return dp[index][ntob][status]=max(notsell,sell);
        }
        else{
            int buys = 0;
            int notbuy = buy(prices,index+1,ntob,status,dp);
            if(ntob<=1)
                buys = -prices[index] + buy(prices,index+1,ntob+1,1,dp);
            return dp[index][ntob][status]=max(buys,notbuy);
        }
        
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(3,vector<int>(2,-1))); 
        return buy(prices,0,0,0,dp);
    }
};