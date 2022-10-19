class Solution {
public:
    int reverse(int x) {
        if(x==0){
            return 0;
        }
        string min="2147483648";
        string max="2147483647";
        bool neg=false;
        if(x<0){
            neg = true;
        }
        string s;
        int i=0;
        while(x){
            s.push_back(abs(x%10)%10+'0');
            x = abs(x);
            x/=10;
            i++;
        }
        if(i==10 && neg){
            for(int i=0;i<=9;i++){
                if(s[i]<min[i]){
                    return -1*stoi(s);
                }
                else if(s[i]==min[i]){
                    continue;
                }
                else{
                    return 0;
                }
            }
            return -1*stoi(s);
        }
        else if(i==10 && !neg){
            for(int i=0;i<=9;i++){
                if(s[i]<max[i]){
                    return stoi(s);
                }
                else if(s[i]==max[i]){
                    continue;
                }
                else{
                    return 0;
                }
            }
            return stoi(s);
        }
        else{
            if(neg)
                return -1*stoi(s);
            else
                return stoi(s);
        }
    }
};