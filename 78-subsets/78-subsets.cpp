class Solution {
public:
    void helper(vector<int>& nums,int index,set<vector<int>>& res,vector<int> curr){
        if(index==nums.size()){
            return ;
        }
        else{
            for(int i =index;i<nums.size();i++){
                curr.push_back(nums[i]);
                res.insert(curr);
                helper(nums,i+1,res,curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> curr;
        vector<vector<int>> ans;
        ans.push_back(curr);
        helper(nums,0,res,curr);
        
        for(auto& x:res){
            ans.push_back(x);
        }
        return ans;
    }
};