class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 2;
        int n = fruits.size();
        if(n==1 || n==2){
            return n;
        }
        
        unordered_map<int,int> mpp;
        mpp[fruits[0]]++;
        mpp[fruits[1]]++;
        int i = 0,j=2;
        int count = 2;
        while(j<n){
            
            if(mpp.find(fruits[j])!=mpp.end()){
                mpp[fruits[j]]++;
                count++;
            }
            else{
                if(mpp.size()<2){
                    mpp[fruits[j]]++;
                    count++;
                }
                else{
                    mpp[fruits[j]]++;
                    count++;
                    
                    while(mpp.size()>2 && i<j){
                        mpp[fruits[i]]--;
                        count--;
                        if(mpp[fruits[i]]==0){
                            mpp.erase(fruits[i]);
                        }
                        i++;
                    }
                }
            }
            
            ans = max(ans,count);
            j++;
        }
        
        return ans;
    }
};