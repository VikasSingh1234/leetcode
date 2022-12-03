class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mpp;
        vector<pair<int,char>> p;
        int n = s.length();
        for(int i=0;i<n;i++){
            mpp[s[i]]++;
        }
        for(auto it:mpp)
        {
            p.push_back({it.second,it.first});
        }
        sort(p.begin(),p.end(),greater<pair<int,char>>());
        int i = 0;
        for(auto x:p){
            int c = x.first;
            while(c--){
                s[i++]=x.second; 
            }
        }
        return s;
    }
};