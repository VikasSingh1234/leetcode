class Solution {
public:
    int ways(int index,string s,int n,vector<int> &dp){
        if(dp[index]!=-1){
            return dp[index];
        }
        
        if(s[index]=='0'){
            return 0;
        }
        
        int res = ways(index+1,s,n,dp);
        
        if(index+1<n && (s[index]=='1'|| (s[index]=='2' && s[index+1]<='6'))){
            res+=ways(index+2,s,n,dp);
        }
        
        dp[index] = res;
        // cout<<index<<" "<<res<<endl;
        return res;
        
    }
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+1,-1);
        dp[n] = 1;
        return ways(0,s,n,dp);
    }
};