class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int n = bank.size();
        vector<int> visited(n,0);
        
        for(int i=0;i<n;i++){
            if(start==bank[i]){
                visited[i] = 1;
            }
        }
        
        queue<pair<string,int>> q;
        q.push({start,0});
        while(!q.empty()){
            string s = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            if(s==end){
                return steps;
            }
            int cnt;
            for(int i=0;i<n;i++){
                cnt = 0;
                if(visited[i]){
                    continue;
                }
                for(int j = 0;j<8;j++){
                    if(s[j]!=bank[i][j]){
                        cnt++;
                    }
                }
                
                if(cnt==1){
                    q.push({bank[i],steps+1});
                    visited[i] = 1;
                }
            }
        }
        return -1;
    }
};