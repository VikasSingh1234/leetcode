class Solution {
public:
    double average(vector<int>& salary) {
        int smallest = 1e9;
        int largest = 0;
        int n = salary.size();
        double sum = 0;
        
        for(auto x:salary){
            sum+=x;
            if(smallest>x) smallest = x;
            if(largest<x) largest = x;
        }
        
        sum -= (smallest+largest);
        
        return sum/(n-2);
    }
};