class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        long int maj1 =1e10,maj2=1e10;
        int count1=0,count2=0;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            if(maj1 == nums[i])
                count1++;
            else if(maj2==nums[i])
                count2++;
            else if(count1==0){
                count1=1;
                maj1=nums[i];
            }
            else if(count2==0){
                count2=1;
                maj2=nums[i];
            }
            else{
                count1--;
                count2--;
            }
        }
        count1= 0;
        count2 = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maj1){
                count1++;
            }
            if(nums[i]==maj2){
                count2++;
            }
        }
        
        if(count1>nums.size()/3)
            res.push_back(maj1);
        if(count2>nums.size()/3)
            res.push_back(maj2);
        
        return res;
    }
};