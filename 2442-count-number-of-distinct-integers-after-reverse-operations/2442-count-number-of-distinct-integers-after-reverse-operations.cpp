class Solution {
public:
    int reverse(int n){
        int rev=0;
        
        while(n){
            rev = rev*10+n%10;
            n/=10;
        }
        return rev;
    }
    
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> s;
        int size = nums.size();
        for(int i=0;i<size;i++){
            s.insert(nums[i]);
            s.insert(reverse(nums[i]));
        }
        
        return s.size();
    }
};