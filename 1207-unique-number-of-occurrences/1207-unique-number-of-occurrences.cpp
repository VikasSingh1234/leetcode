class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mpp;
        set<int> count;
        int n=arr.size();
        for(int i=0;i<n;i++){
            mpp[arr[i]]++;
        }
        
        for(auto x:mpp){
            count.insert(x.second);
        }
        
        if(count.size()==mpp.size())
            return true;
        
        return false;
    }
};