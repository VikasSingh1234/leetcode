class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> win;
        map<int,int> loss;

        int n = matches.size();
        
        for(int i=0;i<n;i++){
            if(loss.find(matches[i][0])==loss.end())
                win[matches[i][0]]++;
            
            loss[matches[i][1]]++;
            
            if(win.find(matches[i][1])!=win.end()){
                win.erase(matches[i][1]);
            }
        }
        
        vector<int> w;
        vector<int> l;
        
        for(auto x:win){
            w.push_back(x.first);
        }
        
        for(auto y:loss){
            if(y.second==1)
                l.push_back(y.first);
        }
        
        return {w,l};
    }
};