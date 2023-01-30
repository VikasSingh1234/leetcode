class Solution {
public:
    int tribonacci(int n) {
        int T0 = 0,T1=1,T2=1;
        
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 1;
        
        for(int i=3;i<=n;i++){
            int temp = T0+T1+T2;
            T0 = T1;
            T1 = T2;
            T2 = temp;
        }
        
        return T2;
    }
};