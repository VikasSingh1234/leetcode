class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector<pair<int,int>> box;
        int n = boxTypes.size()-1;
        int ans = 0;
        for(auto it : boxTypes){
            box.push_back({it[1],it[0]});
        }
        
        sort(box.begin(),box.end());
        
        while(n>=0 && truckSize>0){
            int wt = box[n].first;
            int q = box[n].second;
            
            if(q <= truckSize){
                ans+=wt*q;
                truckSize-=q;
            }
            else{
                ans+=truckSize*wt;
                truckSize = 0;
            }
            n--;
            
        }
        return ans;    
    }
};