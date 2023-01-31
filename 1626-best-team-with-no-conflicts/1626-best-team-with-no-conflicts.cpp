class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<vector<int>> p;
        int n = scores.size();
        
        for(int i=0;i<n;i++){
            p.push_back({-ages[i],-scores[i]});
        }
        
        vector<int> dp(n,0);
        sort(p.begin(),p.end());
        
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j>=0;j--){
                if(-p[i][1]<=-p[j][1]){
                    dp[i] = max(dp[i],dp[j]-p[i][1]);
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};