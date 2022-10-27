class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>> adj(n);
        
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        
        queue<pair<int,pair<int,int>>> q;
        
        q.push({0,{src,k+1}});
        vector<int> fare(n,1e9);
        fare[src] = 0;
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            int price = it.first;
            int airport = it.second.first;
            int fuel = it.second.second;
            
            if(fuel==0){
                continue;
            }
           
            for(auto x:adj[airport]){
                int p = x.second;
                int port = x.first;
                
                if((p+price)<fare[port]){
                    fare[port] = p+price;
                    q.push({fare[port],{port,fuel-1}});
                }
            }
        }
        
        if(fare[dst]!=1e9){
            return fare[dst];
        }
        return -1;
    }
};



