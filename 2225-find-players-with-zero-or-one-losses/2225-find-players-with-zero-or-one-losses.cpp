class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> res;
        vector<int> zero,one;
        unordered_map<int,int> mpp;

        for(int i=0;i<matches.size();i++){
            if(mpp.find(matches[i][0])==mpp.end()){
                mpp[matches[i][0]] = 0;
            }
            
            if(mpp.find(matches[i][1])!=mpp.end()){
                mpp[matches[i][1]] += 1;  
            }
            else{
                mpp[matches[i][1]] = 1;
            }
        }
        // for(auto x: mpp){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        for(auto x:mpp){
            if(x.second==0){
                zero.push_back(x.first);
            }
            else if(x.second==1){
                one.push_back(x.first);
            }
        }
        
        sort(zero.begin(),zero.end());
        sort(one.begin(),one.end());
        res.push_back(zero);
        res.push_back(one);
        return res;
    }
};