class Solution {
public:
    void dfs(int node,vector<vector<int>>& isConnected,vector<bool> &visited){
        visited[node] = true;
        int i = 0;
        while(i<isConnected.size()){
            if(isConnected[node][i]){
                if(!visited[i]){
                    dfs(i,isConnected,visited);
                }
            }      
            i++;
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int res = 0;
        int V = isConnected.size();
        vector<bool> visited(V,false);
        for(int i = 0;i<V;i++){
            if(!visited[i]){
                dfs(i,isConnected,visited);
                res++;
            }
                
        }
        
        return res;
    }
};