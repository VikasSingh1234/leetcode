class Solution {
public:
    int countOdds(int low, int high) {
        if(high%2 || low%2){
            return ((high-low)/2)+1;
        }
        else {
            return (high-low)/2;
        }
    }
};