//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int> ans;
        vector<vector<int>> visited(n,vector<int>(m,false));
        queue<pair<pair<int,int>,int>> q;
        
        int count = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    visited[i][j] = true;
                }
                if(grid[i][j]==1){
                    count++;
                }
            }
        }
        
        int delrow[4] = {1,-1,0,0};
        int delcol[4] = {0,0,1,-1};
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            int node = it.second;
            int row = it.first.first;
            int col = it.first.second;
            
            for(int i=0;i<4;i++){
                int r = row+delrow[i];
                int c = col+delcol[i];
                
                if(r>=0 && c>=0 && r<n && c<m && grid[r][c]==1 && !visited[r][c]){
                    grid[r][c] = 2;
                    visited[r][c] = true;
                    if(count==1){
                        return node+1;    
                    }
                    else{
                        q.push({{r,c},node+1});
                        count--;
                    }
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends