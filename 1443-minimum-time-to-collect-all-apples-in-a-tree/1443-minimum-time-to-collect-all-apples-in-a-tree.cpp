class Solution {
public:
    int helper(int node,int visited,vector<vector<int>>& adj,vector<bool>& hasApple){
        int totalsum = 0 , childsum = 0;
        for(auto x: adj[node]){
            if(x==visited) continue;
            childsum = helper(x,node,adj,hasApple);
            
            if(childsum || hasApple[x]){
                totalsum += 2+childsum;
            }
        }
        return totalsum;
    }
    

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        int m = edges.size();
        for(int i = 0;i<m;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        return helper(0,-1,adj,hasApple);
    }
};






