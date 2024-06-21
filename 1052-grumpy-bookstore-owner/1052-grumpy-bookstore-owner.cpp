class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum = 0;
        int n = grumpy.size();
        int i = 0;
        int maxSum = 0;
        
        int result = 0;
        
        while(i<n && i<minutes){
            if(grumpy[i]==1){
                sum+=customers[i];
            }
            else{
                result+=customers[i];
            }
            i++;
        }
        maxSum = sum;
        for(;i<n;i++){
            if(grumpy[i]==1){
                sum+=customers[i];
            }
            else{
                result+=customers[i];
            }
            
            if(grumpy[i-minutes]==1){
                sum-=customers[i-minutes];
            }
            
            maxSum = max(maxSum,sum);
        }
        
        result+=maxSum;
        
        return result;
    }
};