class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        map<int,int> m,tj;
        if(n==1){
            return 1;
        }
        int s = trust.size();
        for(int i=0;i<s;i++){
            m[trust[i][0]]++;
            tj[trust[i][1]]++;
        }
        
        for(int i=1;i<=n;i++){
            if(tj.find(i)!=tj.end() && m.find(i)==m.end()){
                if(tj[i]==n-1){
                    return i;
                }
            }
        }
        return -1;
    }
};