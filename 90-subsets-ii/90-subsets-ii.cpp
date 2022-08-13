class Solution {
public:
    
    void generateSubsets(vector<int> nums,int idx,vector<int> subsets,vector<vector<int>>& res){
        res.push_back(subsets);
        
        for(int i=idx;i<nums.size();i++){
            if(i>idx && nums[i]==nums[i-1]){
                continue;
            }
            subsets.push_back(nums[i]);
            generateSubsets(nums,i+1,subsets,res);
            subsets.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subsets={};
        sort(nums.begin(),nums.end());
        generateSubsets(nums,0,subsets,res);
        return res;
    }
};