class Solution {
public:
    random_device rd;
    mt19937 mt;
    uniform_int_distribution<int> dist;

    int partition(vector<int>& v, int left, int right)
    {
        int pivot = left + rand() % (right - left);
        swap(v[right], v[pivot]);
        pivot = right;

        for(int i = left; i < right; i++)
        {
            if(v[i] > v[pivot]) swap(v[i], v[left++]);
        }
        
        swap(v[pivot], v[left]);
        return left;
    }
    int quickSelect(vector<int>& nums, int left, int right, int k)
    {
        if(left >= right) return nums[left];
        int pivot = partition(nums, left, right);

        if(pivot == k-1) return nums[pivot];
        else if(pivot > k-1) return quickSelect(nums, left, pivot-1, k);
        else return quickSelect(nums, pivot+1, right, k);
    }

    int heap(vector<int>& nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int num : nums)
        {
            pq.push(num);
            if(pq.size() > k) pq.pop();
        }

        return pq.top();
    }

    int findKthLargest(vector<int>& nums, int k) {

        return heap(nums, k);
        // mt = mt19937(rd());
        // dist = uniform_int_distribution<int>(0, nums.size()-1);
        srand(time(NULL));

        return quickSelect(nums, 0, nums.size()-1, k);
    }
};