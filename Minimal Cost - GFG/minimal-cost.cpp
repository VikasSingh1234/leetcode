//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        if(n==1) return 0;
        if(n==2) return abs(height[n-1]-height[n-2]);
        vector<int> dp(n,INT_MAX);
        
        dp[0] = 0;
        dp[1] = abs(height[1]-height[0]);
    
        for(int i=2;i<=n-1;i++){
            for(int j = 1;j<=k && i>=j;j++)
                dp[i] = min(dp[i],dp[i-j]+abs(height[i]-height[i-j]));
        }
        
        return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends