class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mpp;
        
        for(int i=0;i<t.length();i++){
            mpp[t[i]]++;
        }
        
        int left = 0;
        int right = 0;
        int start = 0;
        int res = INT_MAX;
        int counter = mpp.size();
        
        while(right<s.size()){
            
            if(mpp.find(s[right])!=mpp.end()){
                mpp[s[right]]--;
                if((mpp[s[right]])==0)
                    counter--;
                right++;
            }
            else{
                right++;
            }
            
            while(counter==0){
                if((right-left)<res){
                    res = right-left;
                    start = left;
                }
                
                if(mpp.find(s[left])!=mpp.end()){
                    mpp[s[left]]++;
                    if(mpp[s[left]]>0){
                        counter++;
                    }
                    left++;
                }
                else{
                    left++;
                }
            }
        }
        
        if(res==INT_MAX){
            return "";
        }
        else{
            return s.substr(start,res);
        }
    }
};