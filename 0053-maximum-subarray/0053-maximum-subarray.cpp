class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = INT_MIN;
        int res = INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(sum<0){
                sum = nums[i];
            }
            else{
                sum+=nums[i];
            }
            res = max(res,sum);
        }
        
        return res;
    }
};