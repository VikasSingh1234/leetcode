class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        
        // check if line is parallel to x axis
        bool flag = true;
        for(int i=1;i<n;i++){
            if(coordinates[i][0]!=coordinates[0][0]){
                flag = false;
            }
        }
        
        if(flag){
            return true;
        }
        
        // check slope of each point with staring point 
        if(coordinates[1][0]==coordinates[0][0]){
            return false;
        }
        double slope = double(coordinates[1][1]-coordinates[0][1])/double(coordinates[1][0]-coordinates[0][0]);
        
        for(int i=2;i<n;i++){
            double s = double(coordinates[i][1]-coordinates[0][1])/double(coordinates[i][0]-coordinates[0][0]);
            if(s!=slope){
                return false;
            }
        }
        
        return true;
    }
};