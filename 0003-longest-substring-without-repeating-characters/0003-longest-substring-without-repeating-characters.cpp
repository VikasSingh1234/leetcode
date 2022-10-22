class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int left = 0;
        int right = 0;
        unordered_map<char,int> mpp;
        
        while(right<s.size()){
            if(mpp.find(s[right])!=mpp.end()){
                
                while(left<right){
                    if(s[left] == s[right]){
                        left++;
                        break;
                    }
                    else{
                        mpp.erase(s[left]);
                        left++;
                    }
                }
                mpp[s[right]] = 1;
            }
            else{
                mpp[s[right]] = 1;
                if(res<=mpp.size()){
                    res = mpp.size();
                }
            }
            right++;
        }
        
        return res;
        
    }
};