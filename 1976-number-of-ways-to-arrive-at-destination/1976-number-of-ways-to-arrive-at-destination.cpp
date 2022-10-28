class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        int m = roads.size();
        for(int i=0;i<m;i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> q;
        vector<long long> dist(n,1e15),ways(n,0);
        int mod = 1e9 + 7;
        q.push({0,0});
        ways[0] =1;
        dist[0]=0;
        while(!q.empty()){
            auto [d,node] = q.top();
            q.pop();
            
            for(auto x: adj[node]){
                long int pathwt = x.second;
                int newnode = x.first;
                
                if((pathwt+d) <dist[newnode]){
                    ways[newnode] = ways[node];
                    dist[newnode] = pathwt+d;
                    q.push({dist[newnode],newnode});
                }
                else if(pathwt+d==dist[newnode]){
                    ways[newnode] = (ways[newnode] + ways[node])%mod; 
                }
            }
        }
        return ways[n-1]%mod;
    }
};