class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0;
        int n = nums.size();
        int count = 0;
        int ans = 0;
        while(j<n){
            if(nums[j]==0){
                count++;
            }
            j++;
            while(i<j && count>k){
                if(nums[i]==0){
                    count--;
                }
                i++;
            }
            ans = max(ans,j-i);
            
        }
        return ans;
    }
};