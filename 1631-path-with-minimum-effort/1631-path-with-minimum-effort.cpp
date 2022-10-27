class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        
        pq.push({0,{0,0}});
        vector<vector<int>> diff(m,vector<int>(n,1e9));
        diff[0][0] = 0;
        
        int delrow[4] = {1,-1,0,0};
        int delcol[4] = {0,0,1,-1};
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            int d = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            if(r==m-1 && c==n-1){
                return d;
            }
            
            for(int i=0;i<4;i++){
                int newrow = r+delrow[i];
                int newcol = c+delcol[i];
                
                if(newrow>=0 && newrow<m && newcol>=0 && newcol<n){
                    if(diff[newrow][newcol]!=1e9){
                        if(diff[newrow][newcol]>max(d,abs(heights[newrow][newcol]-heights[r][c]))){
                            diff[newrow][newcol] =  max(d,abs(heights[newrow][newcol]-heights[r][c]));
                            pq.push({diff[newrow][newcol],{newrow,newcol}});
                        }
                        
                    }
                    else{
                        diff[newrow][newcol] =  max(d,abs(heights[newrow][newcol]-heights[r][c]));
                        pq.push({diff[newrow][newcol],{newrow,newcol}});
                    }
                }
            }
            
        }
        
        return 0;
    }
};