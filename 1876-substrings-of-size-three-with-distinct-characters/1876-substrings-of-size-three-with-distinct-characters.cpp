class Solution {
public:
    int countGoodSubstrings(string s) {
        if(s.length()<=2){
            return 0;
        }
        unordered_map<char,int> mpp;
        mpp[s[0]]++;
        mpp[s[1]]++;
        int res = 0;
        for(int i=2;i<s.length();i++){
            mpp[s[i]]++;
            if(mpp.size()==3){
                res++;
            }
            if(mpp[s[i-2]]>1){
                mpp[s[i-2]]--;
            }
            else{
                mpp.erase(s[i-2]);
            }
        }
        return res;
    }
};