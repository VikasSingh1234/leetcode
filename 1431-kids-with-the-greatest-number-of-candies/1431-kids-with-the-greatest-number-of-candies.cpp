class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        int maxi = 0;
        int n = candies.size();
        vector<bool> res(n,false);
        for(int i=0;i<n;i++){
            maxi = max(maxi,candies[i]);
        }
        
        for(int i=0;i<n;i++){
            if(candies[i]+extraCandies>=maxi){
                res[i] = true;
            }
        }
        
        return res;
    }
};