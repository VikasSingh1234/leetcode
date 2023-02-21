class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        if(nums.size()==1){
            return nums[0];
        }
        
        while(low < high){
            int mid = low+(high-low)/2;
            
            if (mid % 2) {
                mid--;
            }
            if (nums[mid] != nums[mid + 1]) {
                high = mid;
            } else {
                low = mid + 2;
            }
        }
        
        return nums[low];
    }
};