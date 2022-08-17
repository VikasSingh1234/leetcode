class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> s={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        set<string> res;
        // char ch;
        string st;
        string ans;
        for(int i=0;i<words.size();i++){
            st = words[i];
            ans ="";
            for(int j=0;j<st.size();j++){
                ans.append(s[st[j]-'a']);
            }
            res.insert(ans);
        }
        return res.size();
    }
};