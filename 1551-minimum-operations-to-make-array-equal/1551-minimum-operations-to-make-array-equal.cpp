class Solution {
public:
    int minOperations(int n) {
        int totalsum = 0,result = 0;
        
        for(int i=0;i<n;i++){
            totalsum+=(2*i +1);
        }
        
        totalsum = totalsum/n;
        
        for(int i = 0;i<n/2;i++){
            result+=(totalsum - (2*i+1));
        }
        
        return result;
    }
};