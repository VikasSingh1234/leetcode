class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int diff=abs(target-nums[0]+nums[1]+nums[2]);
        int res = nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.size()-2;i++){
            int l = i+1;
            int h = nums.size()-1;
            while(l<h){
                int sum =(nums[i]+nums[l]+nums[h]);
                
                if(sum==target){
                    return target;
                }
                else{
                    if(sum>target){
                        
                        if(abs(target-sum)<abs(diff)){
                            res = sum;
                            diff = abs(target-sum);
                        }
                        h--;
                    }
                    else{
                        
                        if(abs(target-sum)<abs(diff)){
                            res = sum;
                            diff = abs(target-sum);
                        }
                        
                        l++;
                    }
                }
            }
        }
        
        return res;
    }
};