class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>>> adj(n);
        int m = times.size();
        for(int i=0;i<m;i++){
            adj[times[i][0]-1].push_back({times[i][1]-1,times[i][2]});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        vector<int> dist(n,1e9);
        dist[k-1] = 0;
        pq.push({0,k-1});
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            int node = it.second;
            int d = it.first;
            
            for(auto x:adj[node]){
                if(d+x.second<dist[x.first]){
                    dist[x.first] = d+x.second;
                    pq.push({dist[x.first],x.first});
                }
            }
        }
        int minTime = 0;  
        for(auto x: dist){
            minTime = max(minTime,x);
        }
        
        if(minTime==1e9){
            return -1;
        }
        else{
            return minTime;
        }
    }
};