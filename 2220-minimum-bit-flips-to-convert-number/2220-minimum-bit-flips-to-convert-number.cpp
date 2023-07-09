class Solution {
public:
    int minBitFlips(int start, int goal) {
        int num = start^goal;
        int ans = 0;
        
        while(num){
            if(num%2) ans++;
            num = num/2;
        }
        return ans;
    }
};