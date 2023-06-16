//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here
        
        vector<int> dp(n,1),hash(n);
        int maxi = 0;
        int last_ind = 0;
        for(int i = 0;i<n;i++){
            hash[i] = i;
            for(int prev_ind=0;prev_ind<i;prev_ind++){
                if(arr[prev_ind]<arr[i]  && 1+dp[prev_ind]>dp[i]){
                    dp[i] = 1+dp[prev_ind];
                    hash[i] = prev_ind;
                }
            }
            
            if(dp[i]>maxi){
                maxi = dp[i];
                last_ind = i;
            }
        }
        
        vector<int> ans;
        ans.push_back(arr[last_ind]);
        while(hash[last_ind]!=last_ind){
            last_ind = hash[last_ind];
            ans.push_back(arr[last_ind]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends