class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int low = 0;
        int high = nums.size()-1;
        
        while(low<=high){
            cout<<low<<" "<<high<<endl;
            int mid = low+(high-low)/2;
            int inc = 0;
            if(nums[mid]==target){
                return mid;
            }
            
            if(nums[low]<nums[mid]){
                if(nums[low]<=target && nums[mid]>target){
                    high = mid-1;
                    continue;
                }
            }
            else{
                inc = 1;
            }
            if(nums[mid]<nums[high]){
                if(nums[mid]<target && nums[high]>=target){
                    low = mid+1;
                    continue;
                }
            }
            else{
                inc = 2;
            }
            
            if(inc==2){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
            
        }
        
        return -1;
    }
};