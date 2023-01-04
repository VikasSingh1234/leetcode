class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k==1){
            return nums;
        }
        
        deque<int> q;
        vector<int> ans;
        int n = nums.size();
        int i = 0;
        for(int j=0;j<n;j++){
            
            while(!q.empty() && q.back() < nums[j]){
                q.pop_back();
            }
            q.push_back(nums[j]);
            
            if(j-i+1==k){
                ans.push_back(q.front());
                
                if(q.front() == nums[i]){
                    q.pop_front();
                }
                
                i++;
            }
                
        }
       
        return ans;
    }
};