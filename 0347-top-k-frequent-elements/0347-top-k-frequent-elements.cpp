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
    void sort(map<int, int>& M,int k,vector<int> &ans)
    {
        set<pair<int, int>, comp> S(M.begin(),M.end());
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
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> frequency;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            frequency[nums[i]]++;
        }
        sort(frequency,k,ans);
        return ans;
    }
};