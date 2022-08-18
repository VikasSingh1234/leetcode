class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int> m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
        }
        vector<int> v;
        for(auto x:m){
            v.push_back(x.second);
        }
        
        sort(v.begin(),v.end());
        int numint = 0,count=0;
        if(v.size()==1){
            return 1;
        }
        for(int i=v.size()-1;i>0;i--){
            if(numint>=arr.size()/2){
                break;
            }
            count++;
            numint += v[i];
        }
        return count;
    }
};