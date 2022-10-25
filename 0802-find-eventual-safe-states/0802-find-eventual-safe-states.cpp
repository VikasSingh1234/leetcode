class Solution {
public:
    bool dfs(int node,vector<vector<int>>& adj,vector<int> &visited,vector<int> &path){
        path[node] = 1;
        visited[node] = 1;
        
        for(auto x: adj[node]){
            if(!visited[x]){
                if(dfs(x,adj,visited,path)){
                    return true;
                }
            }
            else if(path[x]){
                return true;
            }
        }
        path[node] = 0 ;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> visited(graph.size(),0);
        vector<int> path(graph.size(),0);
        
        for(int i=0;i<graph.size();i++){
            if(!visited[i]){
                dfs(i,graph,visited,path);
            }
        }
        
        vector<int> res;
        for(int i=0;i<path.size();i++){
            if(path[i]==0){
                res.push_back(i);
            }
        }
        
        return res;
    }
};