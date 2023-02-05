class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        
        int m = s.length(),n=p.length();
        if(m<n){
            return ans;
        }
        
        int a[26]={0},b[26]={0};
    
        for(int i=0;i<n;i++){
            a[p[i]-'a']++;
            b[s[i]-'a']++;
        }
        
        int count = 0;
        for(int i = 0; i < 26; i++) {
            if(a[i] == b[i])
                count++;
        }
        
        for (int i = n; i < m; i++) {
            int r = s[i] - 'a', l = s[i-n] - 'a';
            if (count == 26)
                ans.push_back(i-n);
            b[r]++;
            if (b[r] == a[r]) {
                count++;
            } else if (b[r] == a[r] + 1) {
                count--;
            }
            b[l]--;
            if (b[l] == a[l]) {
                count++;
            } else if (b[l] == a[l] - 1) {
                count--;
            }
        }
        if(count==26){
            ans.push_back(m-n);
        }
        return ans;
    }
};