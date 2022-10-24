class Solution {
    int result = 0;
public:
    
    bool isUniqueChars(string s){
        vector<int> mpp(26,0);
        for(auto c:s){
            if(mpp[c-'a']==1){
                return false;
            }
            else{
                mpp[c-'a']++;
            }
        }
        return true;
    }
    
    
    void dfs(vector<string>& arr,string concat,int index){
        bool isUniqueChar = isUniqueChars(concat);
        
        if(isUniqueChar){
            if(concat.length()>result){
                result = concat.length();
            }
        }

        if(index == arr.size() || !isUniqueChar){
            return;
        }
        
        for(int i = index; i < arr.size(); i++){
            dfs(arr, concat + arr[i], i + 1);
        }
    }
    
    int maxLength(vector<string>& arr) {
        if (arr.size() == 0) {
            return 0;
        }

        dfs(arr, "", 0);

        return result;
    }
};