class Solution {
public:
    bool check(string s,int n){
        int left = 0;
        
        for(int i=0;i<2*n;i++){
            if(s[i]=='('){
                left++;
            }
            else{
                if(left){
                    left--;
                }
                else{
                    return false;
                }
            }
        }
        
        if(left==0)
            return true;
        else
            return false;
    }
    void generate(int n,string s,vector<string> &ans,int l,int r){
        if(l==n && r==n){
            if(check(s,n))
                ans.push_back(s);
            return ;
        }
        if(l>n || r>n){
            return ;
        }
        s.push_back('(');
        generate(n,s,ans,l+1,r);
        s.pop_back();
        s.push_back(')');
        generate(n,s,ans,l,r+1);
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        generate(n,s,ans,0,0);
        return ans;
    }
};