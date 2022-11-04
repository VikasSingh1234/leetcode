class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans = 0;
        int i = 0;
        int count = 0;
        int n = nums.size();
        for (int j = 0; j < n; j++) {
            if (nums[j] & 1){
                k--;
                count = 0;
            }
            while (k == 0){
                k += (nums[i++] & 1);
                ++count;
            }
            ans += count;
        }
        return ans;
    }
};