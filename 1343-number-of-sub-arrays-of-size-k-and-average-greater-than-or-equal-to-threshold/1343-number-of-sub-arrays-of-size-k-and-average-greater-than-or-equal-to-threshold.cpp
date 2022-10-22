class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        if(arr.size()<k){
            return 0;
        }
        
        int res = 0;
        int sum = 0;
        for(int i=0;i<arr.size();i++){
            if(i < k-1){
                sum+=arr[i];
                continue;
            }
            else{
                sum+=arr[i];
                if(sum/k >= threshold){
                    res++;
                }
                
                sum-=arr[i-k+1];
            }
        }
        return res;
    }
};