// class Solution {
// public:
//     bool checkInclusion(string s1, string s2) {
//         unordered_map<char,int> mpp1(26,0),mpp2(26,0);
//         for()
//     }
// };


class Solution {
    bool check(vector<int> mpp1,vector<int> mpp2)
    {
        for(int i=0;i<26;i++)
        {
            if(mpp1[i]!=mpp2[i])
                return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.length()<s1.length())
            return false;
        // cout<<s1.length()<<endl;
        vector<int> mpp1(26,0),mpp2(26,0);
        
        for(auto it:s1)
        {
            mpp1[it-'a']++;
        }
        int n = s1.length();
        int i=0,j=0;
        
        // for(int k=0;k<26;k++){
        //     cout<<mpp1[k]<<" ";
        // }
        // cout<<endl;
        for(j=0;j<n;j++){
            mpp2[s2[j]-'a']++;
        }
        
        
        
        while(j<s2.length()){
            // for(int k=0;k<26;k++){
            //     cout<<mpp2[k]<<" ";
            // }
            // cout<<endl;
            if(check(mpp1,mpp2)){
                return true;
            }
            mpp2[s2[i++]-'a']--;
            mpp2[s2[j++]-'a']++;
        }
        if(check(mpp1,mpp2)){
            return true;
        }
        return false;
    }
};