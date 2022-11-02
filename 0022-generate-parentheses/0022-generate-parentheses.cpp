class Solution {
public:
    
    void generate(int n,string s,vector<string> &ans,int l,int r){
        if(l==n && r==n){
            ans.push_back(s);
            return ;
        }
        
        if(l<n){
            generate(n,s+'(',ans,l+1,r);
        }
        if(r<l){
            generate(n,s+')',ans,l,r+1);
        }        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        generate(n,s,ans,0,0);
        return ans;
    }
};