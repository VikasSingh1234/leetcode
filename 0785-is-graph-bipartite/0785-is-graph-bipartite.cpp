class Solution {
public:
    
    bool check(int node,int c,vector<vector<int>>& graph,vector<int> &color){
        color[node] = c;
        
        for(auto x:graph[node]){
            if(color[x]==-1){
                if(!check(x,c^1,graph,color)){
                    return false;
                }
            }
            else if(color[x]==color[node]){
                return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int>  color(V,-1);
        
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(!check(i,0,graph,color)){
                    return false;
                }
            }
        }
        return true;
        
    }
};