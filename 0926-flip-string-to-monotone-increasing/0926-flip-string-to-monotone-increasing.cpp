class Solution {
public:
    
    int minFlipsMonoIncr(string s) {
        int ans = 0, flip = 0;
        int n = s.length();
        
        for (int i = 0;i<n;i++) {
            if (s[i] == '0') {
                ans = min(flip, ans + 1);
            } 
            else {
                flip++;
            }
        }
        return ans;
    }
};