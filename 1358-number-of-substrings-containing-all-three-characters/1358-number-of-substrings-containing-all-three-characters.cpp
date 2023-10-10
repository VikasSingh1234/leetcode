class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> mpp(3,0);
        int ans = 0;
        int left = 0, right = 0;
        int n = s.length();
        
        while(right<n){
            
            if(s[right]=='a' || s[right]=='b' || s[right]=='c'){
                mpp[s[right]-'a']+=1;
                while(mpp[0] && mpp[1] && mpp[2]){
                    mpp[s[left++]-'a']--;
                }
                ans+=left;
            }
            right++;
        }
        return ans;
    }
};