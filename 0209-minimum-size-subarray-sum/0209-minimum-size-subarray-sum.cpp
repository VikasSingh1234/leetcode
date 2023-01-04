class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0,end= 0;
        long int currsum = 0;
        int ans = 1e9;
        int n = nums.size();
        while(end<n){
            currsum+=nums[end];
            
            while(currsum>=target){
                ans = min(ans, end - start + 1);
                currsum -= nums[start++]; 
            }
            end++;
        }
        
        return ans==1e9 ? 0:ans;
    }
};