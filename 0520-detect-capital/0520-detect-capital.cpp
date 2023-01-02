class Solution {
public:
    bool capital(string word){
        int i=1;
        int n = word.length();
        
        while(i<n){
            if(word[i]>=97 && word[i]<=122){
                return false;
            }
            i++;
        }
        
        return true;
    }
    bool small(string word){
        int i=1;
        int n = word.length();
        
        while(i<n){
            if(word[i]>= 65 && word[i]<=90){
                return false;
            }
            i++;
        }
        
        return true;
    }
    bool detectCapitalUse(string word) {
        if(word[0]>90){
            return small(word);
        }
        else{
            return capital(word)||small(word);
        }
    }
};