class Solution {
public:
    int partitionString(string s) {
        vector<int> mpp(26,0);
        int ans = 1;
        int n = s.length();
        
        for(int i=0;i<n;i++){
            if(mpp[s[i]-'a']==1){
                for(int j=0;j<26;j++){
                    mpp[j] = 0;
                }
                ans++;
            }
            mpp[s[i]-'a'] = 1;
        }
        
        return ans;
        
    }
};