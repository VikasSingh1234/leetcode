class Solution {
public:
   
    static bool sortbysec(const pair<int,int> &a, const pair<int,int> &b)
    {
        return (a.second < b.second);
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        
        vector<pair<int,int>> p;
        for(int i=0;i<pairs.size();i++){
            p.push_back(make_pair(pairs[i][0],pairs[i][1]));
        }
        sort(p.begin(),p.end(),sortbysec);
        
        int count = 1;
        int j=1,i=0;
        while(i<p.size() && j<p.size()){
            
            if(p[i].second < p[j].first){
                
                count++;
                i = j;
                j++;
                continue;
            }
            j++;
        }
        
        return count;
        
    }
};