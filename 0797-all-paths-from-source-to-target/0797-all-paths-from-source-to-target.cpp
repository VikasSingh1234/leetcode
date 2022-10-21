class Solution {
public:
    
    void dfs(vector<vector<int>>& graph,vector<vector<int>> &paths,vector<int> ans,int node,vector<bool> visited){
        ans.push_back(node);
        visited[node] = true;
        if(node==graph.size()-1){
            paths.push_back(ans);
            visited[node] = false;
            return ;
        }
        
        for(auto it: graph[node]){
            if(!visited[it]){
                dfs(graph,paths,ans,it,visited);
            }
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> ans;
        vector<bool> visited(graph.size(),false);
        dfs(graph,paths,ans,0,visited);
        return paths;
    }
};