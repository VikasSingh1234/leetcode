//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long count(int n) {
        // your code here
        // if(n==1) return 1;
        // if(n==2) return 2;
        
        int p = 0;
        
        for(int i=1;i<n;i++){
            p+=i;
        }
        return pow(2,p);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.count(n) << "\n";
    }

    return 0;
}

// } Driver Code Ends