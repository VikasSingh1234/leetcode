//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findK(vector<vector<int>> &a, int n, int m, int k)
    {
        // Your code goes here
        int up = 0,down  = n-1;
        int left = 0,right = m-1;
        
        while(up<down || left<right){
            for(int i = left;i<=right;i++){
                if(k==1){
                    return a[up][i];
                }
                k--;
            }
            ++up;
            
            for(int i = up;i<=down;i++){
                if(k==1){
                    return a[i][right];
                }
                k--;
            }
            --right;
            
            for(int i = right;i>=left;i--){
                if(k==1){
                    return a[down][i];
                }
                k--;
            }
            --down;
            
            for(int i = down;i>=up;i--){
                if(k==1){
                    return a[i][left];
                }
                k--;
            }
            ++left;
        }
    }

};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        vector<vector<int>> a(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }

        Solution obj;

        cout<< obj.findK(a, n, m, k) << "\n";
        
       
    }
}
// } Driver Code Ends