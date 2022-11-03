class Solution {
public:
    int stock(vector<int>& prices,int index,int k,vector<vector<int>> &dp){
        if(index==prices.size())
            return 0;
        
        if(dp[index][k]!=-1){
            return dp[index][k];
        }
        if(k==0){
            return 0;
        }
        
        bool buy = (k%2==0);
        // if no transaction on this day
        int notrans = stock(prices,index+1,k,dp);
        int trans = -1e9;
        if(buy){
            trans = -prices[index] + stock(prices,index+1,k-1,dp); 
        }
        else{
            trans = prices[index] + stock(prices,index+1,k-1,dp); 
        }
        dp[index][k] = max(trans,notrans);
        return dp[index][k];
        
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2*k+1,-1));
        return stock(prices,0,2*k,dp); 
    }
};
