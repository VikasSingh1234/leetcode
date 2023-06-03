//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

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
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends

int findFloor(int v[], long long n, long long x){
        
        // Your code here
        int ans = -1;
        long long s= 0, e = n-1;
        
        while(s<=e){
            long long mid = s+(e-s)/2;
            if(v[mid]>x){
                e = mid-1;
            }
            else{
                ans = mid;
                s = mid+1;
            }
        }
        if(ans==-1){
            return -1;
        }
        return v[ans];
    }
    
int findCeil(int v[], long long n, long long x){
        
        // Your code here
        int ans = -1;
        long long s= 0, e = n-1;
        
        while(s<=e){
            long long mid = s+(e-s)/2;
            if(v[mid]<x){
                s = mid+1;
            }
            else{
                ans = mid;
                e = mid-1;
            }
        }
        if(ans==-1){
            return -1;
        }
        return v[ans];
        
    }    
    

pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    sort(arr,arr+n);
    return {findFloor(arr,n,x),findCeil(arr,n,x)};
}