class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n,0);
        int p = 1;
        result[0] = 1;
        
        for(int i=1;i<n;i++){
            p*=nums[i-1];
            result[i] = p;
        }
        p = 1;
        for(int i=n-2;i>=0;i--){
            p*=nums[i+1];
            result[i] *= p;
        }
        
        
        return result;
    }
};