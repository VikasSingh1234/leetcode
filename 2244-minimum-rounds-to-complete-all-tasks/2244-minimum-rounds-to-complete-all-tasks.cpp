class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        sort(tasks.begin(),tasks.end());
        int n = tasks.size();
        
        int ans = 0;
        float count = 1;
        for(int i=1;i<n;i++){
            if(tasks[i]==tasks[i-1]){
                count++;
            }
            else if(count==1){
                return -1;
            }
            else{
                ans+= ceil(count/3);
                count = 1;
            }
        }
        
        if(count==1){
            return -1;
        }
        else{
            ans+= ceil(count/3);
        }
        return ans;
    }
};