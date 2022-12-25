class Solution {
public:
    string longestPalindrome(string s) {
        int maxlen = 0;
        int start = 0;
        int end = 0;
        int n = s.length();
        for(int i=0;i<n;i++){
            int l = i,r =i;
            
            while(l>=0 && r<=n-1 && s[l]==s[r]){
                if((r-l+1)>maxlen){
                    maxlen = r-l+1;
                    start = l;
                    end = r;
                }
                l--;
                r++;
            }
            
            l = i,r =i+1;
            
            while(l>=0 && r<=n-1 && s[l]==s[r]){
                if((r-l+1)>maxlen){
                    maxlen = r-l+1;
                    start = l;
                    end = r;
                }
                l--;
                r++;
            }
        }
        return s.substr(start,maxlen);
    }
};