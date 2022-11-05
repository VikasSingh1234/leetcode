class Solution {
    int mod = 1e9+7;
public:
    int combination(int n,int r){
        if(r == 0) return 1;
        vector<int> v(r+1,0);
        v[0] = 1;
        for(int i=1; i<=n; i++){
            for(int j=r; j>0; j--)
                v[j] = ((v[j] % mod) + (v[j-1] % mod)) % mod;
        }
        return v[r];
    }
    int numberOfWays(int startPos, int endPos, int k) {
        int diff = abs(endPos-startPos);
        
        if((k-diff)>=0 && (k-diff)%2==0){
            int r = (k-diff)/2;
            return combination(k,r);
        }
        return 0;
    }
};