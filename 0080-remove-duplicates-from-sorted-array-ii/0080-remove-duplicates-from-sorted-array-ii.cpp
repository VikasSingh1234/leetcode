class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int dup  = 0;
        int c = 1;
        int pos = 1;
        int n = nums.size();
        
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                c++;
                if(c<=2){
                    nums[pos++] = nums[i];
                }
                else{
                    dup++;
                    continue;
                }
            }
            else{
                nums[pos++] = nums[i];
                c = 1;
            }
        }
        
        return (n-dup);
    }
};