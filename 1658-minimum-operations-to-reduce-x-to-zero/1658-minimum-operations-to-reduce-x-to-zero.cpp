class Solution {
public:
//     int helper(vector<int>& nums,int start,int end,int target){
//         if(start>end){
//             return 1e6;
//         }
        
//         if(target==0){
//             return 0;
//         }
        
//         int left = 1e6;
//         int right = 1e6;
        
//         if(nums[start]<=target){
//             left = 1+helper(nums,start+1,end,target-nums[start]);
//         }
            
//         if(nums[end]<=target){
//             right = 1+helper(nums,start,end-1,target-nums[end]);
//         }    
        
//         return min(left,right);
//     }
    int minOperations(vector<int>& nums, int x) {
        
        // int ans = helper(nums,0,nums.size()-1,x);
        // if(ans < 1e6){
        //     return ans;
        // }
        // else{
        //     return -1;
        // }
        int ans = 1e9;
        unordered_map<int,int> m;
        int n = nums.size();
        
        long int sum = 0;
        
        for(int i=n-1;i>=0;i--){
            sum+=nums[i];
            m[sum] = n-i;
            if(sum==x){
                if(ans>n-i){
                    ans = n-i;
                }
            }
        }
        
        sum = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum==x){
                if(ans>i+1){
                    ans = i+1;
                }
            }
            else if(m.find(x-sum)!=m.end()){
                if(i<(n-m[x-sum])){
                    if((i+1+m[x-sum])<ans){
                        ans = i+1+m[x-sum];
                    }
                }
            }
        }
        
        if(ans!=1e9){
            return ans;
        }
        
        return -1;
    }
};