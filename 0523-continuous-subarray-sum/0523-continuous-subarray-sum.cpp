class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int, int> mpp{{0, 0}};
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (!mpp.count(sum % k))
                mpp[sum % k] = i + 1;
            else if (mpp[sum % k] < i)
                return true;
        }
        return false;
    }
};