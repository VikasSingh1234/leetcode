class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int i = 0, j = i+1,n = s.length();
        while(i<n){
            if(s[i]==' '){
                i++;
                continue;
            }
            else{
                j = i+1;
                while(j<n && s[j]!=' '){
                    j++;
                }
                
                reverse(s.begin()+i,s.begin()+j);
                i = j+1;
            }
        }
        
        // remove spaces
        j = 0;
        for(int i=0;i<n;i++){
            if((s[i]==' ' && i==0) || (s[i]==' ' && s[i-1]==' ')){
                continue;
            }
            else{
                s[j++]  = s[i];
            }
        }
        if(s[j-1]==' '){
            return s.substr(0,j-1);
        }
        else{
            return s.substr(0,j);
        }
    }
};