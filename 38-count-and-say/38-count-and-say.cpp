class Solution {
public:
    
    string generate_next_string(string s){
        int count = 1;
        string ans = "";
        for(int i=0;i<s.length()-1;i++){
            if(s[i]==s[i+1]){
                count++;
            }
            else{
                ans.push_back(count+'0');
                ans.push_back(s[i]);
                count=1;
            }
        }
        ans.push_back((count + '0'));
        ans.push_back(s[s.length()-1]);
        
        return ans;
    }
    string countAndSay(int n) {
        if(n==1)
            return "1";
        string s="11";
        
        for(int i=3;i<=n;i++){
            string itr = generate_next_string(s);
            s = itr;
        }
        return s;
        
    }
};