class Solution {
public:
    
    int find(int x,vector<int> &minchar) {
        if (minchar[x] == x) {
            return x;
        }
        
        return minchar[x] = find(minchar[x],minchar);
    }
    
    void Union(int x, int y,vector<int> &minchar) {
        x = find(x,minchar);
        y = find(y,minchar);
        
        if (x == y) {
            return;
        }
        
        if (x < y) {
            minchar[y] = x;
        } else {
            minchar[x] = y;
        }
    }
    
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> minchar(26,-1);
        for (int i = 0; i < 26; i++) {
            minchar[i] = i;
        }
        
        for (int i = 0; i < s1.size(); i++) {
            Union(s1[i] - 'a', s2[i] - 'a',minchar);
        }
        
        string ans;
        
        for (char c : baseStr) {
            ans += (char)(find(c - 'a',minchar) + 'a');
        }
        
        return ans;
    }
};