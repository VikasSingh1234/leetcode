class Solution {
public:
    bool halvesAreAlike(string str) {
        int left = 0,right=0;
        
        int n = str.length();
        for(int i=0;i<n/2;i++){
            if(str[i]=='a'|| str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O' ||str[i]=='U')
            {
                left++;
            }
        }
        
        for(int i=n/2;i<n;i++){
            if(str[i]=='a'|| str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O' ||str[i]=='U')
            {
                right++;
            }
        }
        
        if(left==right)
            return true;
        
        return false;
    }
};