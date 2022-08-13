
class Solution {
    public:
        vector<int> findSubstring(string s, vector<string>& words ) {
        unordered_map<string, int> m;

        for (string word : words)
            m[word]++;
            
        int n = s.length();
        int num = words.size();
        int len = words[0].length();
            
        vector<int> positions;
        for (int i = 0; i < n - num * len + 1; i++) {
            unordered_map<string, int> seen;
            int j = 0;
            for (; j < num; j++) {
                string word = s.substr(i + j * len, len);
                if (m.find(word) != m.end()) {
                    seen[word]++;
                if (seen[word] > m[word])
                    break;
                }
                else 
                    break;
            }
            if (j == num) positions.push_back(i);
        }
        return positions;
    }
};