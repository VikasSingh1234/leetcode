class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int minx = max(ax1,bx1);
        int maxx = min(ax2,bx2);
        
        int miny = max(ay1,by1);
        int maxy = min(ay2,by2);
        
        if(maxx>minx && maxy>miny){
            return ((ax2-ax1)*(ay2-ay1)+(bx2-bx1)*(by2-by1))-((maxx-minx)*(maxy-miny));
        }
        else{
            return ((ax2-ax1)*(ay2-ay1)+(bx2-bx1)*(by2-by1));
        }
    }
};