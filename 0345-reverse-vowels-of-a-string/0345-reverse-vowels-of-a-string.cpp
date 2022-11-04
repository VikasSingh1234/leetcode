class Solution {
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.length()-1;
        unordered_map<char,int> mpp;
        mpp = {{'a',1},{'A',1},{'e',1},{'E',1},{'i',1},{'I',1},{'O',1},{'o',1},{'u',1},{'U',1}};
        
        while(i<j){
            if(mpp.find(s[i])==mpp.end()){
                i++;
                continue;
            }
            
            if(mpp.find(s[j])==mpp.end()){
                j--;
                continue;
            }
            
            swap(s[i],s[j]);
            i++;
            j--;
        }
        
        return s;
    }
};