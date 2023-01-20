class Solution {
public:
    void subset(vector<int> nums,int idx,set<vector<int>> &s,vector<int> v){
        if(idx==nums.size()){
            if(v.size()>1)
                s.insert(v);
            return ;
        }
        
        if(v.size()>1){
            s.insert(v);
        }
        
        for(int i = idx;i<nums.size();i++){
            if(v.size()==0){
                v.push_back(nums[i]);
                subset(nums,i+1,s,v);
                v.pop_back();
            }
            else{
                if(nums[i]>=v[v.size()-1]){
                    v.push_back(nums[i]);
                    subset(nums,i+1,s,v);
                    v.pop_back();
                }
                else{
                    continue;
                }
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> s;
        subset(nums,0,s,{});
        
        vector<vector<int>> ans;
        for(auto x:s){
            ans.push_back(x);
        }
        
        return ans;
    }
};