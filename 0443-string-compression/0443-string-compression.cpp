class Solution {
public:
    int compress(vector<char>& chars) {
        int ans = 0;
        int i = 0;
        int n = chars.size();
        while (i<n) {
            int count = 1;
            while (i + count < n && chars[i + count] == chars[i]) {
                count++;
            }
            chars[ans++] = chars[i];
            if (count > 1) {
                for (char c : to_string(count)) {
                    chars[ans++] = c;
                }
            }
            i += count;
        }
        
        return ans;
    }
};