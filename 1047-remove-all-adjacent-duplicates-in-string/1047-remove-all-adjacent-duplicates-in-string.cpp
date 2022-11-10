class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        int n = s.length();
        int j = -1;
        for(int i=0;i<n;i++){
            if(j==-1 || ans[j]!=s[i]){
                ans.push_back(s[i]);
                j++;
            }
            else {
                while(j>=0 && ans[j]==s[i]){
                    j--;
                    ans.pop_back();
                }
            }
        }
        
        return ans;
    }
};