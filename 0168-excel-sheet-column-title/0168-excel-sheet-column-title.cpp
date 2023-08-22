class Solution {
public:
    string convertToTitle(int columnNumber) {
        vector<char> v = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
        string s;
        while(columnNumber>0){
            int rem = columnNumber%26;
            rem  = rem-1;
            
            if(rem>=0){
                s = v[rem] + s;
                columnNumber = columnNumber/26;
            }
            else{
                s = v[25] + s;
                columnNumber = (columnNumber/26) -1;
            }
            
        }
        return s;
        
    }
};