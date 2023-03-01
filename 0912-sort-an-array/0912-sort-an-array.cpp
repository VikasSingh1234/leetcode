class Solution {
public:
    
    void heapify(vector<int>& nums, int N, int i)
    {
        int largest = i;
        int l = 2 * i + 1;

        int r = 2 * i + 2;

        if (l < N && nums[l] > nums[largest])
            largest = l;

        if (r < N && nums[r] > nums[largest])
            largest = r;

        if (largest != i) {
            swap(nums[i], nums[largest]);
            heapify(nums, N, largest);
        }
    }
    
    void heapSort(vector<int>& nums, int N)
    {
        for (int i = N / 2 - 1; i >= 0; i--)
            heapify(nums, N, i);

        for (int i = N - 1; i > 0; i--) {
            swap(nums[0], nums[i]);
            heapify(nums, i, 0);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        heapSort(nums,n);
        return nums;
    }
};