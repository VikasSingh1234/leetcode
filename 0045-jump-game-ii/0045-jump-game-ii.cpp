class Solution {
public:
    int jump(vector<int>& nums) {
        int maxreach = 0;
        int curr = 0;
        int jumps = 0;
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            maxreach = max(maxreach,nums[i]+i);
            if (i == curr) {
                jumps++;
                curr = maxreach;
		    }
        }
        return jumps;
    }
};