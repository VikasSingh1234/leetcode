class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> p;
        map<int,int> mpp;
        int profit = 0;
        
        int n = profits.size();
        
        for(int i=0;i<n;i++){
            p.push_back({capital[i],profits[i]});
        }
        
        sort(p.begin(),p.end());
        
        int i = 0;
        while(k--){
    
            while(i<n && p[i].first<=w){
                mpp[p[i].second]++;
                i++;
            }
            
            cout<<mpp.size()<<" ";
            if(mpp.size()==0){
                return w;
            }
            else{
                int key = mpp.rbegin()->first;
                w+=key;
                if(mpp.rbegin()->second==1){
                    mpp.erase(key);
                }
                else{
                    mpp[key]--;
                }
            }
        }
        
        return w;
        
        
    }
};