class Solution {
public:
    bool isPalindrome(int x) {
        string exp = to_string(x);
        int n = exp.length();
        for(int i=0;i<n/2;i++)
            if(exp[i]!=exp[n-1-i])
                return false;
        return true;
    }
};