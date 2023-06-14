class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxprofit = 0;
        int res=-1;
        int min = nums[0];
        for(int i=0;i<nums.size();i++){
            if(min>nums[i]){
                min = nums[i];
                maxprofit = 0 ;
            }
            else{
                if(maxprofit<(nums[i]-min)){
                    maxprofit = nums[i]-min;
                    if(res<maxprofit){
                        res = maxprofit;
                    }
                }
            }
        }
        return res;
    }
};