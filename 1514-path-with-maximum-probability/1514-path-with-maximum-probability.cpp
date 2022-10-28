class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> adj(n);
        int m = edges.size();
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        
        vector<double> prob(n,0);
        queue<pair<double,int>> q;
        
        q.push({1,start});
        prob[start] = 1;
        
        while(!q.empty()){
            auto [p,node] = q.front();
            q.pop();
            
            for(auto x:adj[node]){
                auto [edgenode,edgepb] = x;
                
                if(p*edgepb > prob[edgenode]){
                    prob[edgenode] = p*edgepb;
                    q.push({p*edgepb,edgenode});
                }
            }
        }
        
        return prob[end];
    }
};