class Solution {
public:
    
    void Subset(set<vector<int>> &v,vector<int> sub,int idx,vector<int> nums){
        if(idx>=nums.size()){
            return ;
        }
        
        Subset(v,sub,idx+1,nums);
        sub.push_back(nums[idx]);
        sort(sub.begin(),sub.end());
        v.insert(sub);
        Subset(v,sub,idx+1,nums);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> v;
        vector<vector<int>> m;
        vector<int> subsets={};
        v.insert(subsets);
        Subset(v,subsets,0,nums);
        Subset(v,subsets,1,nums);
        
        for(auto x:v){
            m.push_back(x);
        }
        return m;
    }
};