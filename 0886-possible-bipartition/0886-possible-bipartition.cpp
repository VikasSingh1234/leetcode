class Solution {
public:
    bool check(int node,int c,vector<vector<int>>& adj,vector<int> &color){
        color[node] = c;
        
        for(auto x:adj[node]){
            if(color[x]==-1){
                if(!check(x,c^1,adj,color)){
                    return false;
                }
            }
            else if(color[x]==color[node]){
                return false;
            }
        }
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        vector<int>  color(n,-1);
        vector<vector<int>> adj(n);
        
        for(int i=0;i<dislikes.size();i++){
            adj[dislikes[i][0]-1].push_back(dislikes[i][1]-1);
            adj[dislikes[i][1]-1].push_back(dislikes[i][0]-1);
            
        }
        
        
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!check(i,0,adj,color)){
                    return false;
                }
            }
        }
        return true;
    }
};