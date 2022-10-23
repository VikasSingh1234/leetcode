class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int,int> mpp;
        
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]]++;
        }
        
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<arr.size();i++){
            if(mpp[arr[i]]>0){
                mpp[arr[i]]--;
                int search ;
                if(arr[i]>=0){
                     search =2*arr[i];
                }
                else if(arr[i]%2==0){
                    search = arr[i]/2;
                }
                else{
                    return false;
                }
                if(mpp.find(search)!=mpp.end()){
                    if(mpp[search]>0){
                        mpp[search]--;
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        
        return true;
    }
};