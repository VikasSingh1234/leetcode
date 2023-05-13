class Solution {
    int mod = 1000000007;
public:
    
    int dfs(int end, int zero, int one,vector<int> &dp) {
        if (dp[end] != -1)
            return dp[end];
        int count = 0;
        if (end >= one) {
            count += dfs(end - one, zero, one,dp);
        }
        if (end >= zero) {
            count += dfs(end - zero, zero, one,dp);
        }
        dp[end] = count % mod;
        return dp[end];
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1,-1);
        dp[0] = 1;
        
        int answer = 0;
        for (int end = low; end <= high; ++end) {
            answer += dfs(end, zero, one,dp);
            answer %= mod;
        }
        return answer;
    }
};