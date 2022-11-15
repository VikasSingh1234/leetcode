class Solution {
    int mod = 1e9 + 7;
public:
    int pow(long long x, long long y) {
        if(y==0) return 1;
        else if(y%2 == 0)        
            return pow((x*x) % mod, y/2);
        else                             
            return (x*pow((x*x) % mod, (y-1)/2)) % mod;
    }
    
    int countGoodNumbers(long long n) {
        long long odd = n/2;
        long long even = n/2 + n%2;
        long long ans = pow(4,odd);
        ans = ans*pow(5,even);
        return ans%mod;
    }
    
};