class Solution {
public:
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        set<vector<int>> ans;
        vector<int> triplets;
        for(int i=0;i<nums.size()-2;i++){
            int l = i+1;
            int h = nums.size()-1;
            while(l<h){
                
                if((nums[i]+nums[l]+nums[h])==0){
                    triplets.push_back(nums[i]);
                    triplets.push_back(nums[l]);
                    triplets.push_back(nums[h]);
                    ans.insert(triplets);
                    triplets = {};
                    l++;
                }
                else{
                    if((nums[i]+nums[l]+nums[h])>0){
                        h--;
                    }
                    else{
                        l++;
                    }
                }
            }
        }
        for(auto x:ans){
            res.push_back(x);
        }
        
        return res;
    }
};