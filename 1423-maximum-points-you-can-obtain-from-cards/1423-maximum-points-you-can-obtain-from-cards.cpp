class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int curr = 0;
        int minSum = INT_MAX;
        int totalSum = 0;
        int n = cardPoints.size();
        k = n-k;
        for(int i=0;i<n;i++){
            curr+=cardPoints[i];
            totalSum+=cardPoints[i];
            if(i==k-1) minSum = min(minSum,curr);
            if(i>=k){
                curr-= cardPoints[i-k];
                minSum = min(minSum,curr);
            }
        }
        
        if(minSum==INT_MAX){
            return totalSum;
        }
        else{
            return  totalSum-minSum;   
        }
         
        
    }
};