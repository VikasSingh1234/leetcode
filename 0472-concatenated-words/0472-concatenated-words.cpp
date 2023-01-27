class Solution {
public:
    bool find(string s,int start,int end,unordered_map<string,int> &mpp){
        if(mpp.find(s.substr(start,end+1-start))!=mpp.end()){
            return true;
        }
        return false;
    }
    
    void helper(string s,int start,unordered_map<string,int> &mpp,vector<string> &ans){
        if(start==s.length()){
            if(!ans.empty() && ans.back()==s)
                return ;
            ans.push_back(s);
            return ;
        }

        for(int end = start;end<s.length();end++){
            if(start==0 && end==s.length()-1){
                continue;
            }

            if(find(s,start,end,mpp)){
                // cout<<start<<" "<<end<<s.substr(start,end-start+1)<<"-->";
                helper(s,end+1,mpp,ans);
                // cout<<endl;
            }
        }

    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
        int n = words.size();
        vector<string> ans;
        unordered_map<string,int> mpp;
        
        for(int i=0;i<n;i++){
            mpp[words[i]]++;
        }

        for(int i=0;i<n;i++){
            helper(words[i],0,mpp,ans);
        }
        
        return ans;
    }
};