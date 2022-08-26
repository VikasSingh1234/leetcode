class Solution {
public:
   bool reorderedPowerOf2(int N) {
        string givenNum = countdigit(N);
        for (int i = 0; i < 32; i++)
            if (givenNum == countdigit(1 << i)) return true;
        return false;
    }
    
    string countdigit(int n) {
        string ans = to_string(n);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
