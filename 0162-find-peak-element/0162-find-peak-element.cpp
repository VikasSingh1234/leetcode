class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n =nums.size();
        int start=0,last=n-1;
        int ans = nums[0];
        while(start<last){
            // find mid element
            int mid = start +(last-start)/2;
            
            // compare with left and right
            if(nums[mid]<nums[mid+1]){
                start = mid+1;
            }
            else{
                last = mid;
            }
        }
        
        return start;
    }
};