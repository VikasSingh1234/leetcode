//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int nums[], int n, int target) {
	    // code here
	    
	    int min=-1,max=-1,mid;
        int start=0,last=n-1;
        
        while(start<=last){
            mid = start +(last-start)/2;
            if(nums[mid] == target){
                max=mid;
                start = mid+1;
            }
            else if(nums[mid]>=target){
                last = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        start = 0,last=n-1;
        while(start<=last){
            mid = start +(last-start)/2;
            if(nums[mid] == target){
                min=mid;
                last = mid-1;
            }
            else if(nums[mid]<target){
                start = mid+1;
            }
            else{
                last = mid-1;
            }
        }
        if(max==-1 && min==-1){
            return 0;
        }
        return max-min+1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends