class Solution {
public:
    int binary_search(vector<int>& nums,int target){
        int l = 0;
        int h = nums.size()-1;
        int index = -1;
        
        while (l <= h)
        {
            int mid = (l + h) / 2;
            if (nums[mid] <= target){
                l = mid + 1;
            }   
            else{
                index = mid;
                h = mid - 1;
            }
        }

        return index;
    }
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int m = queries.size();
        vector<int> ans;
        
        for(int i=1;i<n;i++){
            nums[i]+=nums[i-1];
        }
        
        for(int i=0;i<m;i++){
            if(queries[i]>=nums[n-1]){
                ans.push_back(n);
            }
            else if(queries[i]<nums[0]){
                ans.push_back(0);
            }
            else{
                ans.push_back(binary_search(nums,queries[i]));
            } 
        }
       return ans;
    }
    
};