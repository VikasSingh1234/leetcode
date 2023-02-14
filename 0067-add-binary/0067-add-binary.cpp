class Solution {
public:
    string addBinary(string a, string b) {
        int n1 = a.length(), n2 = b.length();
        
        int i = n1-1 , j = n2-1;
        string ans;
        int carry = 0;
        while(i>=0 && j>=0){
            if(carry){
                if(a[i]=='1' && b[j]=='1'){
                    ans.push_back('1');
                    carry = 1;
                }
                else if(a[i]=='1' || b[j]=='1'){
                    ans.push_back('0');
                    carry = 1;
                }
                else{
                    ans.push_back('1');
                    carry = 0;
                }
            }
            else{
                if(a[i]=='1' && b[j]=='1'){
                    ans.push_back('0');
                    carry = 1;
                }
                else if(a[i]=='1' || b[j]=='1'){
                    ans.push_back('1');
                    carry = 0;
                }
                else{
                    ans.push_back('0');
                    carry = 0;
                }
            }
            i--;
            j--;
        }
        
        while(i>=0){
            if(carry){
                if(a[i]=='1'){
                    ans.push_back('0');
                    carry = 1;
                }
                else{
                    ans.push_back('1');
                    carry = 0;
                }
            }
            else{
                if(a[i]=='1'){
                    ans.push_back('1');
                    carry = 0;
                }
                else{
                    ans.push_back('0');
                    carry = 0;
                }
            }
            i--;
        }
        
        while(j>=0){
            if(carry){
                if(b[j]=='1'){
                    ans.push_back('0');
                    carry = 1;
                }
                else{
                    ans.push_back('1');
                    carry = 0;
                }
            }
            else{
                if(b[j]=='1'){
                    ans.push_back('1');
                    carry = 0;
                }
                else{
                    ans.push_back('0');
                    carry = 0;
                }
            }
            j--;
        }
        
        if(carry){
            ans.push_back('1');
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};