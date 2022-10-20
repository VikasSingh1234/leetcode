class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int,string> mpp;
        int place = 1;
        string res;
        mpp[1] = "I";
        mpp[5] = "V";
        mpp[10] = "X";
        mpp[50] = "L";
        mpp[100] = "C";
        mpp[500] = "D";
        mpp[1000] = "M";
        
        while(num){
            int digit = num%10;
            
            if(digit==4){
                res.insert(0,mpp[5*place]);
                res.insert(0,mpp[place]);
            }
            else if(digit==9){
                res.insert(0,mpp[10*place]);
                res.insert(0,mpp[place]);
            }
            else if(digit<5){
                for(int i=0;i<digit;i++){
                    res.insert(0,mpp[place]);
                }
            }
            else{
                for(int i=6;i<=digit;i++){
                    res.insert(0,mpp[place]);
                }
                res.insert(0,mpp[5*place]);
            }
            num/=10;
            place*=10;
        }
        return res;
    }
};