//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    int delrow[4] = {-1,1,0,0};
    int delcol[4] = {0,0,1,-1};
  public:
  void markReplaceorNot(vector<vector<int>>& board,vector<vector<int>>& visited,int x,int y){
        
        int m = board.size();
        int n = board[0].size();
        
        for(int i=0;i<4;i++){
            int newrow = x+delrow[i];
                int newcol = y+delcol[i];
                
                if(newrow>=0 && newrow<m && newcol>=0 && newcol<n && !visited[newrow][newcol] && board[newrow][newcol]==1){
                    visited[newrow][newcol] = 1;
                    markReplaceorNot(board,visited,newrow,newcol);
                }
        }
    }
    int numberOfEnclaves(vector<vector<int>> &board) {
        // Code here
        
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        
        for(int i = 0;i<m;i++){
            if(board[i][0]==1 && !visited[i][0]){
                visited[i][0] = 1;
                markReplaceorNot(board,visited,i,0);
            }
        }
        for(int i = 0;i<m;i++){
            if(board[i][n-1]==1 && !visited[i][n-1]){
                visited[i][n-1] = 1;
                markReplaceorNot(board,visited,i,n-1);
            }
        }
        
        for(int j = 1;j<n;j++){
            if(board[0][j]==1 && !visited[0][j]){
                visited[0][j] = 1;
                markReplaceorNot(board,visited,0,j);
            }
        }
        
        for(int j = 1;j<n;j++){
            if(board[m-1][j]==1 && !visited[m-1][j]){
                visited[m-1][j] = 1;
                markReplaceorNot(board,visited,m-1,j);
            }
        }
        
        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==1 && visited[i][j]==0){
                    count++;
                }
            }
        }
        
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends