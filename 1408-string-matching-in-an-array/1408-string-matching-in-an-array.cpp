class Solution {
public:
    void prefix_array(string st, vector<int>& res){
        int n = st.length();
        
        for(int i=1;i<n;i++){
            int j = res[i-1];
            while(j>=1 && st[i]!=st[j]){
                j = res[j-1];
            }
            
            if(st[i]==st[j]){
                j++;
            }
            res[i] = j;
        }
        
    }
    
    bool match(string s,string t){
        if(s.length()>=t.length()){
            int i=0,j=0;
            int n = t.length();
            vector<int> prefix(n,0);
            prefix_array(t,prefix);
            
            while(i<s.length()){
                if(t[j]==s[i]){
                    i++;
                    j++;
                    
                }
                else{
                    if(j!=0){
                        j = prefix[j-1];
                    }
                    else{
                        i++;
                    }
                }
                
                if(j==t.length()){
                    return true;
                }
            }
            return false;
            
        }
        else{
            return false;
        }
        
    } 
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words.size();j++){
                if(i!=j)
                {
                    if(match(words[j],words[i])){
                        ans.push_back(words[i]);
                        break;
                    }
                }
                
            }
        }
        return ans;
    }
};