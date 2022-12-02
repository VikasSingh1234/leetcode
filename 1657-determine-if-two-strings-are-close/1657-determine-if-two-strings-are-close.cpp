class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length()!=word2.length())
            return false;
        
        int n = word1.length();
        
        vector<int> w1(26,0);
        vector<int> w2(26,0);
        
        set<char> a1,a2;
        
        for(int i=0;i<n;i++){
            w1[int(word1[i])-97]++;
            a1.insert(word1[i]);
            w2[int(word2[i])-97]++;
            a2.insert(word2[i]);
        }
        
        sort(w1.begin(),w1.end());
        sort(w2.begin(),w2.end());
        
        if(w1==w2 && a1==a2)
            return true;
        return false;
    }
};