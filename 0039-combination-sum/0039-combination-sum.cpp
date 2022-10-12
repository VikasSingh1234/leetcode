class Solution {
public:
    
    void helper(vector<int> candidates,int target,vector<int> comb,vector<vector<int>>& res,int index){
        if(target==0){
            res.push_back(comb);
            return ; 
        }
        if(target<0){
            return ;
        }
        
        for(int i=index;i<candidates.size();i++){
            comb.push_back(candidates[i]);
            helper(candidates,target-candidates[i],comb,res,i);
            comb.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> comb;
        vector<vector<int>> res;
        sort(candidates.begin(),candidates.end());
        helper(candidates,target,comb,res,0);
        return res;
    }
};