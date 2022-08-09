class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<int,long> mpp;
        int mod = 1e9 +7;
       
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]]=1;
        }
        
       
        long  count = 0;
        for(int i=0;i<arr.size();i++){
            count=1;
            for(int j=0;j<i;j++){
                if((arr[i]%arr[j])==0){
                    count = (count + mpp[arr[j]]*mpp[arr[i]/arr[j]])%mod;
                    // cout<<num<<" ";
                }
            }
            
            mpp[arr[i]] = (count)%mod;
        }
        
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum=(sum+mpp[arr[i]])%mod;
            // cout<<mpp[arr[i]]<<" ";
        }
        
        return sum%mod;
    }
};