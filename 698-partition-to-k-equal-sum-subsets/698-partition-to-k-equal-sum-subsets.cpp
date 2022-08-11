class Solution {
bool helper(vector<int> nums,int start,int temp,vector<bool> &visited,int k,int target)
{
    if(k==1)
    return true;
    if(temp==0)
    return helper(nums,0,target,visited,--k,target);
    if(start>=nums.size())
    return false;
    
    for(int i=start;i<nums.size();i++)
    {
        if (i - 1 >= 0 && nums[i] == nums[i - 1] && !visited[i - 1]) 
        continue;
        if(!visited[i] && temp>=nums[i])
        {
            
            visited[i]=true;
            if(helper(nums,i+1,temp-nums[i],visited,k,target))
            return true;
            visited[i]=false;//backtracking
        }
    }
    return false;//this means partition can't could not be made
}
public:
bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        for(auto it:nums)
            sum+=it;
        if(sum%k!=0)//if the sum is not divisible by the number of partitions
            return false;
        vector<bool> visited(nums.size(),false);
        sort(nums.begin(),nums.end(),greater<int>());
        return helper(nums,0,sum/k,visited,k,sum/k);
    }
};