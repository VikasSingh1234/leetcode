class Solution {
public:
    int Path(int node,vector<vector<int>> &adj, string &s,int &ans){
        int max1 = 0,max2 = 0;
        for(auto x:adj[node]){
            int temp = Path(x,adj,s,ans);
            if(s[x]==s[node]) continue;
            
            if(temp>max1){
                max2 = max1;
                max1 = temp;
            }
            else if(temp>max2){
                max2 = temp;
            }
        }
        
        ans = max(ans,(1+max1+max2));
        return 1+max1;
    }
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        
        for(int i=1;i<n;i++){
            if(parent[i]==-1) continue;
            adj[parent[i]].push_back(i);
        }
        int ans=1;
        Path(0,adj,s,ans);
        return ans;
        
    }
};