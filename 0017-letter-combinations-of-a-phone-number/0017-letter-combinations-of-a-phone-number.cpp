class Solution {
public:
    void bfs(string digits,int i,vector<string> &ans,string t,vector<vector<char>> &button){
        if(i==digits.length()){
            ans.push_back(t);
            return ;
        }
        
        int d = digits[i]-'0';
        
        for(char x:button[d-2]){
            t.push_back(x);
            bfs(digits,i+1,ans,t,button);
            t.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0){
            return ans;
        }
        vector<vector<char>> button={{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
        bfs(digits,0,ans,"",button);
        return ans;
        
    }
};