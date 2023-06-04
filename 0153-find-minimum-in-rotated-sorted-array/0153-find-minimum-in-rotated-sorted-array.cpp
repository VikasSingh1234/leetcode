class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = nums[0];
        
        int s = 0,e = nums.size()-1;
        
        while(s<=e){
            int mid = s+(e-s)/2;
            
            if(nums[s]<=nums[mid]){
                ans = min(ans,nums[s]);
                s = mid+1;
            }
            else{
                ans = min(ans,nums[mid]);
                e = mid-1;
            }
        }
        
        return ans;
        
    }
};