class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        long long int i = n;
        if(n<0){
            i = -1*i;
        }
        
        while(i){
            if(i%2){
                res = res*x;
                i--;
            }
            else{
                x = x*x;
                i=i/2;
            }
        }
        if(n<0)
            return (double(1.0)/res);
        return res;
    }
};