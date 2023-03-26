class Solution {
public:
    int helper(vector<int>& nums,int target){
        int high = nums.size()-1;
        int low = 0;
        int ans = -1;
        int n = nums.size();
        
        if(target>nums[high]) return n-1;
        
        while (low <= high)
        {
            int mid = low + (high-low) / 2 ;
            if (nums[mid] >= target)
            {
                high = mid - 1;
            }
            else
            {
                ans = mid;
                low = mid + 1;
            }
        }
        return ans;
        
    }
    
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int m = queries.size();
        int n = nums.size();
        //sort
        sort(nums.begin(),nums.end());
        
        //return 
        vector<long long> ans;
        //sum
        long long sum = nums[0];
        //prefixsum
        
        vector<long long> prefix(n);
        prefix[0] = nums[0];
        
        //cal prefix , sum
        for(int j=1;j<n;j++){
            sum+=nums[j];
            prefix[j] = prefix[j-1]+nums[j];
        }
        
        
        for(int i=0;i<m;i++){
            int q = queries[i];
            
            //helper
            int idx = helper(nums,q);
            long long op,count=0;
            if(idx==-1 || idx==n-1){
                op = n;
                op = op*q;
                count = abs(sum-op);
            }
            else{
                op = idx+1;
                op = op*q;
                count += (op - prefix[idx]);
                op = n-idx-1;
                op = op*q;
                count += ((sum - prefix[idx]) -op);
            }
            ans.push_back(count);
        }
        return ans;
    }
};