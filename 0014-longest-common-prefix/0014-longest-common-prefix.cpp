class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string res;
        int idx = 0;
        string start = strs[0];
        string end = strs[strs.size()-1];
        while(idx<start.length() && idx<end.length()){
            if(start[idx]==end[idx]){
                res.push_back(start[idx]);
                idx++;
            }
            else{
                break;
            }
        }
        
        return res;
    }
};