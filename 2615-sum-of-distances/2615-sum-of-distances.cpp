class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        
        vector<long long > ans(n,0);
        unordered_map<long long,long long> suml,sumr,cntl,cntr;
        
        for(int i=0;i<n;i++){
            ans[i] = (cntl[nums[i]]*i - suml[nums[i]]);
            suml[nums[i]] += i;
            ++cntl[nums[i]];
        }
        
        for(int i=n-1;i>=0;i--){
            ans[i] += (sumr[nums[i]] - cntr[nums[i]]*i);
            sumr[nums[i]] += i;
            ++cntr[nums[i]];
        }
        return ans;
    }
};