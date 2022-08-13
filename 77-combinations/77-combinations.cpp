class Solution {
public:
    
    void generateCombinations(vector<int> n,int num,int k,vector<int> subset,vector<vector<int>>& res){
        if(subset.size()==k){
            res.push_back(subset);
            return ;
        }
            
        
        for(int i = num;i<n.size();i++){
            subset.push_back(n[i]);
            generateCombinations(n,i+1,k,subset,res);
            subset.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> subset={};
        vector<int> v1;
        for(int i=0;i<n;i++){
            v1.push_back(i+1);
        }
        generateCombinations(v1,0,k,subset,res);
        return res;
    }

};