//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     void toposort(int node,vector<pair<int,int>> adj[],stack<int> &st,vector<int> &visited){
         visited[node] = 1;
         
         for(auto x:adj[node]){
             int newnode = x.first;
             if(!visited[newnode]){
                 toposort(newnode,adj,st,visited);
             }
         }
         st.push(node);
         
     }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        
        vector<pair<int,int>> adj[N];
        vector<int> visited(N,0);
        for(int i=0;i<M;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        
        stack<int> st;
        
        for(int i=0;i<N;i++){
            if(!visited[i]){
                toposort(i,adj,st,visited);
            }
        }
        
        vector<int> dist(N,1e9);
        dist[0] = 0;
        while(!st.empty()){
            int v = st.top();
            st.pop();
            
            for(auto x: adj[v]){
                int vt = x.first;
                int wt = x.second;
                
                if(dist[v]+wt<dist[vt]){
                    dist[vt] = dist[v]+wt;
                }
            }
        }
        
        for(int i=0;i<N;i++){
            if(dist[i]==1e9){
                dist[i] = -1;
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends