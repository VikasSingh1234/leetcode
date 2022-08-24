class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj;
        int count = 0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maj){
                count++;
            }
            else{
                count--;
            }
            
            if(count<=0){
                maj = nums[i];
                count=1;
            }
        }
        return maj;
    }
};