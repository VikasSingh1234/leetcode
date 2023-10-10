class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        vector<int> prefixSum(k+1,0);
        int ans = 0;
        int n = cardPoints.size();
        prefixSum[0] = 0;
        for(int i=1;i<=k;i++){
            prefixSum[i] = prefixSum[i-1] + cardPoints[i-1];
            ans = max(ans,prefixSum[i]);
        }
        int sum = 0;
        for(int i=1;i<=k;i++){
            sum += cardPoints[n-i];
            ans = max(ans,sum+prefixSum[k-i]);
        }
        
        return ans;
        
    }
};