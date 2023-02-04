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
        vector<int> mpp1(26,0),mpp2(26,0);
        
        for (int i = 0; i < s1.length(); i++) {
            mpp1[s1[i] - 'a']++;
            mpp2[s2[i] - 'a']++;
        }

        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (mpp1[i] == mpp2[i])
                count++;
        }

        for (int i = 0; i < s2.length() - s1.length(); i++) {
            int r = s2[i + s1.length()] - 'a', l = s2[i] - 'a';
            if (count == 26)
                return true;
            mpp2[r]++;
            if (mpp2[r] == mpp1[r]) {
                count++;
            } else if (mpp2[r] == mpp1[r] + 1) {
                count--;
            }
            mpp2[l]--;
            if (mpp2[l] == mpp1[l]) {
                count++;
            } else if (mpp2[l] == mpp1[l] - 1) {
                count--;
            }
        }
        return count == 26;
    }
};