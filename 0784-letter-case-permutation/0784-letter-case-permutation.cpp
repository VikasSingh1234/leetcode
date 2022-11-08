class Solution {
public:
    void helper(string s,int index,set<string>& data){
        int l = s.length();
        if(index==l){
            return ;
        }
        
        data.insert(s);
        
        if(s[index]>='0' && s[index]<='9'){
            helper(s,index+1,data);
        }
        else{
            helper(s,index+1,data);
            
            if(s[index]>='a'){
                s[index] = s[index] -32;
                data.insert(s);
                helper(s,index+1,data);
            }
            else{
                s[index] = s[index] +32;
                data.insert(s);
                helper(s,index+1,data);
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