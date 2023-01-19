class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int prefix = 0, ans = 0;

        vector<int> sum(k);
        sum[0] = 1;

        for (int num : nums) {
            prefix = (prefix + num % k + k) % k;
            ans += sum[prefix];
            sum[prefix]++;
        }

        return ans;
    }
};