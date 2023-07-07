class Solution {
public:
    long long  f(vector<vector<int>>& questions,int index,int n,vector<long long > &dp){
        if(index>=n){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        long long  take = questions[index][0] + f(questions,index+questions[index][1]+1,n,dp);
        long long nottake = f(questions,index+1,n,dp);
        
        return dp[index] = max(take,nottake);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n,-1);
        return f(questions,0,n,dp);
    }
};