class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        
        if(n==2){
            return abs(stones[1]-stones[0]);
        }
        
        int forward = 0;
        int backward = 0;
        
        int i = 1;
        forward = max(forward,abs(stones[1]-stones[0]));
        backward = max(backward,abs(stones[2]-stones[0]));
        while(i<n){
            if(i==n-1){
                break;
            }
            
            if(n-i==2){
                forward = max(forward,abs(stones[i+1]-stones[i]));
                i++;
            }
            else{
                forward = max(forward,abs(stones[i+2]-stones[i]));
                i+=2;
            }
        }
        
        i=2;
        while(i<n){
            if(i==n-1){
                break;
            }
            
            if(n-i==2){
                backward = max(backward,abs(stones[i+1]-stones[i]));
                i++;
            }
            else{
                backward = max(backward,abs(stones[i+2]-stones[i]));
                i+=2;
            }
        }
        
        return max(forward,backward);
    }
};