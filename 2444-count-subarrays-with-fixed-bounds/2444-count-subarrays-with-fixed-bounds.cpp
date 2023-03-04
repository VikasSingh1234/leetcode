class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int minp = -1, maxp = -1, leftBound = -1;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < minK || nums[i] > maxK)
                leftBound = i;
            
            if (nums[i] == minK) 
                minp = i;
            if (nums[i] == maxK)
                maxp = i;

            ans += max(0, min(maxp, minp) - leftBound);
        }
        
        return ans;
    }
};