class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int steps = 0;
        int maxCapcity = capacity;
        for(int i=0;i<plants.size();i++){
            if(capacity>=plants[i]){
                capacity -= plants[i];
                steps++;
            }
            else{
                capacity = maxCapcity-plants[i];
                steps += 2*i + 1;
            }
        }
        return steps;
    }
};