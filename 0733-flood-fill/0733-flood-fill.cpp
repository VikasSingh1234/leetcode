class Solution {
public:
    void dfs(vector<vector<int>>& image,int prevcolor,int color,int i,int j,vector<vector<int>>& visited){
        int m = image.size();
        int n = image[0].size();
        if(prevcolor==image[i][j] && !visited[i][j]){
            image[i][j] = color;
            visited[i][j] = 1;
            if(i>0){
                dfs(image,prevcolor,color,i-1,j,visited);
            }
            if(i<m-1){
                dfs(image,prevcolor,color,i+1,j,visited);
            }
            if(j>0){
                dfs(image,prevcolor,color,i,j-1,visited);
            }
            if(j<n-1){
                dfs(image,prevcolor,color,i,j+1,visited);
            }
        }
        else{
            return ;
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int prevcolor = image[sr][sc];
        vector<vector<int>> visited(image.size(),vector<int>(image[0].size(),0));
        dfs(image,prevcolor,color,sr,sc,visited);
        return image;
    }
};