//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    bool partition(int A[], int N,int M,long long int mid){
        int count = 1;
        long long int sum = 0;
        
        for(int i=0;i<N;i++){
            if(sum+A[i]<=mid){
                sum+=A[i];
            }
            else{
                count++;
                if(count>M || A[i]>mid){
                    return false;
                }
                
                sum = A[i];
            }
        }
        
        return true;
    }
    
    long long minTime(int A[], int N, int M)
    {
        long long high = 0;
        int mini = 0;
        
        for(int i=0;i<N;i++){
            high += A[i]; 
            mini  = max(mini,A[i]);
        }
        long long ans = high;
        long long low = mini;
        
        while(low<high){
            long long mid = low+(high-low)/2;
            
            if(partition(A,N,M,mid)){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        
        //code here
        return low;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends