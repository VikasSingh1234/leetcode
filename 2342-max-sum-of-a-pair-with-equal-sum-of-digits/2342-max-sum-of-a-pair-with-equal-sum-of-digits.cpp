class Solution {
public:
    int digitsum(int num){
        int rem=0;
        int ans=0;
        
        while(num){
            rem = num%10;
            ans+=rem;
            num=num/10;
        }
        return ans;
    }
    
    int maximumSum(vector<int>& nums) {
        unordered_map<int,vector<int>> maxsum;
        int sum,ans=-1;
        for(int i=0;i<nums.size();i++){
            sum = digitsum(nums[i]);
            maxsum[sum].push_back(nums[i]);
        }
        sum=0;
        
        for(auto x:maxsum){
            sort(x.second.begin(),x.second.end());
            int n = x.second.size();
            if(n>=2){
                sum = x.second[n-1]+x.second[n-2];
                ans = max(ans,sum);
            }
        }
        
        return ans;
    }
};