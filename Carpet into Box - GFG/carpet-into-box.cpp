//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int carpetBox(int A, int B, int C, int D){
        //code here
        int ans = 0;
        int maxCarpet = max(A,B), minCarpet = min(A,B);
        int maxBox = max(C,D),minBox = min(C,D);
        
        while(maxCarpet>maxBox || minCarpet>minBox){
            int a = maxCarpet;
            int b = minCarpet;
            if(a>maxBox){
                ans++;
                a = a/2;
            }
            else{
                ans++;
                b = b/2;
            }
            
            maxCarpet = max(a,b);
            minCarpet = min(a,b);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends