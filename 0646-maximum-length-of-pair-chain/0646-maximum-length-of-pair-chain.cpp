class Solution {
public:
    static bool sortbysec(const vector<int> &a,const vector<int> &b){
        return a[1] < b[1];
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),sortbysec);
        int last = pairs[0][1], ans = 1, n = pairs.size();
        for(int i=1;i<n;i++){
            if(pairs[i][0]>last){
                last = pairs[i][1];
                ans++;
            }
        }
        return ans;
    }
};