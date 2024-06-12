class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = n-1;
        int mid = 0;
        
        while(i<=j){
            if(nums[i]==0){
                int temp = nums[i];
                nums[i] = nums[mid];
                nums[mid] = temp;
                mid++;
                i++;
            }
            else if(nums[i]==1){
                i++;
            }
            else{
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                j--;
            }
        }
    }
};