class Solution {
public:
    void helper(string s,int index,set<string>& data){
        int l = s.length();
        if(index==l){
            return ;
        }
        else{
            for(int i = index;i<l;i++){
                char original = s[i];
                data.insert(s);
                if(s[i]>='a' && s[i]<='z'){
                    s[i] = s[i]-32;
                    data.insert(s);
                    helper(s,i+1,data);
                    s[i] = original;
                }
                else if(s[i]>='A' && s[i]<='Z'){
                    s[i] = s[i]+32;
                    data.insert(s);
                    helper(s,i+1,data);
                    s[i] = original;
                }
            }
        }
    }
    
    vector<string> letterCasePermutation(string s) {
        set<string> data;
        vector<string> ans;
        helper(s,0,data);
        
        for(auto x: data){
            ans.push_back(x);
        }
        
        return ans;
    }
};