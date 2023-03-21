class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long int ans = 0;
        long long int add;
        int count=0;
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            if(nums[i]==0) count++;
            else{
                add = count;
                add = add*(count+1);
                add = add/2;
                ans+=add;
                count= 0;
            }
        }
        add = count;
                add = add*(count+1);
                add = add/2;
                ans+= add;
        
        return ans;
    }
};