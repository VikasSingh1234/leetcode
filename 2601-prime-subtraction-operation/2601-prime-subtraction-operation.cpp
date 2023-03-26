class Solution {
public:
    void helper(int n,vector<int> &prime)
    {
        bool is_prime[n + 1];
        memset(is_prime, true, sizeof(is_prime));
        is_prime[0] = is_prime[1] = false;
        for (int p = 2; p * p <= n; p++) {
            if (is_prime[p]) {
                for (int i = p * p; i <= n; i += p) {
                    is_prime[i] = false;
                }
            }
        }
        for (int i = 2; i <= n; i++) {
            if (is_prime[i]) {
                prime.push_back(i);
            }
        }
    }
    
    int bs(vector<int>& prime,int target){
        int high = prime.size()-1;
        int low = 0;
        int ans = 0;
        int n = prime.size();
        
            
        while (low <= high)
        {
            int mid = low + (high-low) / 2 ;
            if (prime[mid] >= target)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        // cout<<prime[ans]<<" ";
        return prime[ans];
        
    }
    
    bool primeSubOperation(vector<int>& nums) {
        vector<int> prime;
        helper(1010,prime);
        cout<<prime.size()<<endl;
        int n = nums.size();
        cout<<n<<endl;
        int lowest = nums[n-1];
        
        for(int i = n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                continue;
            }
            else{
                auto t = bs(prime,(nums[i]-nums[i+1]+1));
                nums[i]= nums[i]-t;
                cout<<nums[i]<<" ";
            }
            if(nums[i]<1)
                return false;
        }
        return true;
    }
};