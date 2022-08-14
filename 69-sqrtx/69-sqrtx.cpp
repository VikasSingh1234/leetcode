class Solution {
public:
    int mySqrt(int x) {
        int res=1;
        if(x==0)
            return 0;
        int low = 1,high = x;
        long long int mid;
        while(low<high){
            mid = low+ (high-low)/2;
            if((mid*mid)==x){
                return mid;
            }
            if((mid*mid)>x){
                high = mid;
            }
            else{
                res = mid;
                low = mid+1;
            }
        }
        return res;
    }
};