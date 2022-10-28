class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mpp;
        string original;
        vector<vector<string>> ans;
        vector<string> sets;
        for(auto x:strs){
            original = x;
            sort(x.begin(),x.end());
            mpp[x].push_back(original);
        }
        
        for(auto x:mpp){
            sets.clear();
            for(auto s:x.second){
                sets.push_back(s);
            }
            ans.push_back(sets);
        }
        
        return ans;
    }
};