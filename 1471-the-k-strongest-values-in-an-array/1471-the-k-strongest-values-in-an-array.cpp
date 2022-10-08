class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        vector<int> res;
        sort(arr.begin(),arr.end());
        int m;
        int n = arr.size();
        m = arr[(n-1)/2];
        
        int l = 0;
        int r = n-1;
        
        while(k--){
            if(abs(arr[r]-m)>=abs(arr[l]-m)){
                res.push_back(arr[r]);
                r--;
            }
            else{
                res.push_back(arr[l]);
                l++;
            }
        }
        return res;
    }
};