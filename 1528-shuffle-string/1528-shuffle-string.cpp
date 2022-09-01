class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ans;
        unordered_map<int,char> mpp;
        
        for(int i=0;i<s.length();i++){
            mpp[indices[i]] = s[i];
        }
        
        for(int i=0;i<s.length();i++){
            ans.push_back(mpp[i]);
        }
        return ans;
    }
};