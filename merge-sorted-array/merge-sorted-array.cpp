class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Contraints: nums1.length == m + n
        
        for(int i = 0; i < n; ++i)
        {
            int value = nums2[i];
            // find place from the end of nums1
            nums1[m] = value;
            for(int j = m-1; j >= 0; --j)
            {
                if(value >= nums1[j]) break;
                else
                {
                    int temp = nums1[j];
                    nums1[j] = value;
                    nums1[j+1] = temp;
                }
            }
            m++;
        }
        
    }
};