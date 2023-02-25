class Solution {
public:
    bool partition(vector<int>& position, int m,int mid){
        int Count = 1;
        int lastPos = position[0];
        int n = position.size();
        for(int i=0; i<n; i++ ){

            if(position[i]-lastPos >= mid){
                Count++;
                if(Count==m)
                {
                    return true;
                }
                lastPos = position[i];
            }
        }
        return false;
    }
    
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int start = 0;
        int n = position.size();
        int end=position[n-1];
        int ans = -1;
        

        while(start<=end) {
            int mid = start + (end-start)/2;
            if(partition(position, m, mid)) {
                ans = mid;
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return ans;
        
    }
};