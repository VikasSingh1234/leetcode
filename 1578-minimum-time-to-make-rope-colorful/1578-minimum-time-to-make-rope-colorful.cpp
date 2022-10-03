class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int res = 0;
        int i=0,j=1;
        
        while(i<neededTime.size() && j<neededTime.size()){
            if(colors[i]==colors[j]){
                if(neededTime[i]<neededTime[j])
                {
                    res += neededTime[i];
                    i=j;
                    j++;
                }
                else
                {
                    res += neededTime[j];
                    j++;
                }    
            }
            else{
                i=j;
                j++;
            }
        }
        return res;
    }
};