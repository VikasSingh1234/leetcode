class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int s=0, e = nums.size()-1;
        
        while(s<=e){
            // find mid element
            int mid = s +(e-s)/2;
            
            // compare with left and right
            if(nums[mid]==target){
                return true;
            }
            if(nums[s]<nums[mid]){
                if(target>=nums[s] && target<nums[mid]){
                    e = mid-1;
                }
                else{
                    s = mid+1;
                }
            }
    
            else if((nums[e]>nums[mid])){
                if(target>nums[mid] && target<=nums[e]){
                    s = mid+1;
                }
                else{
                    e = mid-1;
                }
            }
            else{
                if((nums[s]==nums[mid]))
                    s++;
                if((nums[e]==nums[mid]))
                    e--;
            }
            
            
        }
        
        return false;
    }
};