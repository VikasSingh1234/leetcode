class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int res = 0;
        long long int area;
        
        while(l<r){
            area = min(height[l],height[r]);
            area = area*(r-l);
            
            if(res<area){
                res = area;
            }
            
            if(height[l]<=height[r])
                l++;
            else
                r--;
        }
        return res;
    }
};