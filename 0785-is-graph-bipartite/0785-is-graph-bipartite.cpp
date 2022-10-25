class Solution {
public:
    
    bool check(int start,vector<vector<int>>& graph,vector<int> &color){
        queue<int> q;
        
        q.push(start);
        color[start] = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto x: graph[node]){
                if(color[x]==-1){
                    q.push(x);
                    if(color[node]==0)
                        color[x] = 1;
                    else
                        color[x] = 0;
                }
                else if(color[node]==color[x])
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
                if(!check(i,graph,color)){
                    return false;
                }
            }
        }
        return true;
        
    }
};