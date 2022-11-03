class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> mpp;
        int n = words.size();
        string s="ab";
        int ans = 0;
        for(int i=0;i<n;i++){
            s[0]=words[i][1];
            s[1]=words[i][0];
            
            if(mpp.find(s)!=mpp.end()){
                if(mpp[s]>0){
                    ans+=4;
                    mpp[s]--;
                    if(mpp[s]==0){
                        mpp.erase(s);
                    }
                }
            }
            else{
                mpp[words[i]] += 1;
            }
        }
        
        for(auto x:mpp){
            if(x.first[0]==x.first[1]){
                ans +=2;
                break;
            }
        }
        
        return ans;
    }
};