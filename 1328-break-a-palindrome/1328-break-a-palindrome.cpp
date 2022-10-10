class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.length();
        if(n==1)
            return "";
        for(int i=0;i<n;i++){
            if(palindrome[i]!='a'){
                if(n%2 && i==n/2 )
                    continue;
                else{
                    palindrome[i] = 'a';
                    return palindrome;
                }
            }
        }
        
        palindrome[n-1] = palindrome[n-1]+1;
        return palindrome;
    }
};