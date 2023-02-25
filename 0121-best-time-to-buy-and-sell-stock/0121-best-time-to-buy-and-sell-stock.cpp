class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int res=0;
        int min = prices[0];
        for(int i=0;i<prices.size();i++){
            if(min>prices[i]){
                min = prices[i];
                maxprofit = 0 ;
            }
            else{
                if(maxprofit<(prices[i]-min)){
                    maxprofit = prices[i]-min;
                    if(res<maxprofit){
                        res = maxprofit;
                    }
                }
            }
        }
        return res;
    }
};