class Solution {
public:
    int addDigits(int num) {
        while(num/10!=0){
            int newnum = 0;
            
            while(num){
                newnum += num%10;
                num = num/10; 
            }
            
            num = newnum;
            
        }
        
        return num;
    }
};