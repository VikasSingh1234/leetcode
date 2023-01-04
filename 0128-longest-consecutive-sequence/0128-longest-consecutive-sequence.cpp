class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> m;
        if(nums.size()==0){
            return 0;
        }
        
        int n = nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]] = 1;
        }
        
        long long int prev = 1e10;
        int ans = 1;
        int curr = 0;
        for(auto x: m){
            if(prev==1e10){
                curr++;
                prev = x.first;
                continue;
            }
            else{
                if(x.first==prev+1){
                    curr++;
                    prev = x.first;
                    ans = max(ans,curr);
                }
                else{
                    curr = 1;
                    prev = x.first;
                }
            }
        }
        return ans;
    }
};