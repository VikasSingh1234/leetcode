class Solution {
public:
    int fun(string t){
        int count = 0;
        
        for(int i=0; i<t.length();i++){
            if(t[i]=='1'){
                count++;
            }
        }
        
        return count;
    }
    int helper(vector<string>& s, int m, int n,int index,vector<vector<vector<int>>> &dp){
        if(index<s.size() && m>=0 && n>=0){
            if(dp[m][n][index]!=-1){
                return dp[m][n][index];
            }
            int pick = 0,notpick=0;
            int ones = fun(s[index]);
            int zeros = s[index].length()-ones;
            if(m-zeros>=0 && n-ones>=0)
                pick = 1 + helper(s,m-zeros,n-ones,index+1,dp);
            notpick = helper(s,m,n,index+1,dp);
            dp[m][n][index]=max(pick,notpick);
            return dp[m][n][index];
        }
        else{
            return 0;
        }
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(strs.size()+1,-1)));
        return helper(strs,m,n,0,dp);
    }
};