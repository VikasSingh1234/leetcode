class Solution {
public:
    vector<int> Tree(int node,int parent,vector<vector<int>> &adj,string &labels,vector<int> &ans){
        vector<int> count(26);
        count[labels[node]-'a'] = 1;

        for(auto x: adj[node]){
            if(x==parent) continue;
            vector<int> child = Tree(x,node,adj,labels,ans);
            for(int i=0;i<26;i++)
                count[i]+=child[i];
        }
        ans[node] = count[labels[node]-'a'];
        return count;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        int m = edges.size();
        for(int i = 0;i<m;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> ans(n,0);
        Tree(0,-1,adj,labels,ans);
        return ans;
    }
};