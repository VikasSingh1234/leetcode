class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> mpp;
        int sum = 0;
        int count = 0;

        for(int i=0;i<n;i++){
            sum += nums[i]; 

            if(sum==k){
                count++;
            }

            int remSum = sum-k;
            if(mpp.find(remSum)!=mpp.end()){
                count+=mpp[remSum];
            }

            mpp[sum] += 1;

        }

        return count;
    }
};