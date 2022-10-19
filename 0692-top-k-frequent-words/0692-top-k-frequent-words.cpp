struct comp {
    template <typename T>
    bool operator()(const T& l,
                    const T& r) const
    {
        if (l.second != r.second) {
            return l.second > r.second;
        }
        return l.first < r.first;
    }
};

class Solution {
    void sort(map<string, int>& M,int k,vector<string> &ans)
    {
        set<pair<string, int>, comp> S(M.begin(),M.end());
        for (auto& it : S) {
            if(k){
                ans.push_back(it.first);
                k--;
            }
            else{
                break;
            }
        }
    }
public:
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> frequency;
        vector<string> ans;
        for(int i=0;i<words.size();i++){
            frequency[words[i]]++;
        }
        sort(frequency,k,ans);
        return ans;
    }
};