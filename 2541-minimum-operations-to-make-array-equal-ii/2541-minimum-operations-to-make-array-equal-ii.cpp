class Solution {
public:
    long long minOperations(vector<int>& num1, vector<int>& num2, int k) {
        long long int plus = 0,minus=0;
        int n = num1.size();
        for(int i=0;i<n;i++){
            if(num1[i]==num2[i]){
                continue;
            }
            if(k==0)
                return -1;
            
            int diff = abs(num1[i]-num2[i]);
            if(diff%k==0){
                if(num1[i]>num2[i]){
                    minus+= diff/k; 
                }
                else{
                    plus+=diff/k;

                }
            }
            else
                return -1;
        }
        
        if(plus==minus)
            return plus;
        
        return -1;
        
    }
};