class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        int mod = 1e9+7;
        int n = horizontalCuts.size();
        int m = verticalCuts.size();
        int height = 0;
        int width = 0;
        for(int i=1;i<n;i++){
            height = max(height,horizontalCuts[i] - horizontalCuts[i-1]);
        }
        
         for(int j = 1;j<m;j++){
            width = max(width,verticalCuts[j] - verticalCuts[j-1]);
        }
        
        return (1ll*height*width)%mod;
    }
};