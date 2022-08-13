class Solution {
public:
    void permutation(vector<int> nums,int idx,vector<vector<int>>& res){
        if(idx==nums.size()){
            res.push_back(nums);
            return ;
        }
        
        for(int i = idx;i<nums.size();i++){
            if(i!=idx && nums[i]==nums[idx]){
                continue;
            }
            swap(nums[i],nums[idx]);
            permutation(nums,idx+1,res);
        }
        
        return ;
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        permutation(nums,0,res);
        return res;
    }
};