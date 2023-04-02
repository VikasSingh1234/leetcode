class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> p;
        int n = profit.size();
        int m = worker.size();
        
        for(int i=0;i<n;i++){
            p.push_back({difficulty[i],profit[i]});    
        }
        sort(worker.begin(),worker.end());
        sort(p.begin(),p.end());
        
        int i=0,j=0;
        int ans = 0;
        int maxprofit = 0;
        
        while(i<n && j<m){
            if(p[i].first <= worker[j]){
                maxprofit = max(maxprofit,p[i].second);
                i++;
            }
            else{
                ans+=maxprofit;
                j++;
            }
        }
        
        while(j<m){
            ans+=maxprofit;
            j++;
        }
        
        return ans;
    }
};