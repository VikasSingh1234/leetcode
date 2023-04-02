class Solution {
public:
    
    int helper(vector<int>& potions,int num,long long success){
        long long s = num;
        int high = potions.size()-1;
        int low = 0;
        int idx = high+1;
        
        while(low<=high){
            int mid = low+(high-low)/2;
            s = s*potions[mid]; 
            if(s>=success){
                idx = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
            s = s/potions[mid]; 
        }
        
        return idx;
        
    }
    
    
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n = spells.size();
        int m = potions.size();
        vector<int> ans(n);
        
        for(int i=0;i<n;i++){
            ans[i] = m-helper(potions,spells[i],success);
        }
        return ans;
    }
};