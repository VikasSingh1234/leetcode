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
            if(candidates[i]>target)
                break;
            if(i>index && candidates[i]==candidates[i-1]){
                continue;
            }
            comb.push_back(candidates[i]);
            helper(candidates,target-candidates[i],comb,res,i+1);
            comb.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> comb;
        vector<vector<int>> res;
        sort(candidates.begin(),candidates.end());
        helper(candidates,target,comb,res,0);
        return res;
    }
};