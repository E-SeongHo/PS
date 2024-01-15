class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Contraints: nums1.length == m + n
        
        // for(int i = 0; i < n; ++i)
        // {
        //     int value = nums2[i];
        //     // find place from the end of nums1
        //     nums1[m] = value;
        //     for(int j = m-1; j >= 0; --j)
        //     {
        //         if(value >= nums1[j]) break;
        //         else
        //         {
        //             int temp = nums1[j];
        //             nums1[j] = value;
        //             nums1[j+1] = temp;
        //         }
        //     }
        //     m++;
        // }
        
        while(m > 0 && n > 0)
        {
            if(nums1[m-1] >= nums2[n-1])
            {
                nums1[m+n-1] = nums1[m-1];
                m--;
            }
            else
            {
                nums1[m+n-1] = nums2[n-1];
                n--;
            }   
        }
        // because of its in-place sorting, don't need to consider about n == 0
        // which means the left over nums1 elements which didn't move already on their pos properly.
        while(n > 0) // meanse m == 0
        {
            nums1[m+n-1] = nums2[n-1];
            n--;
        }
        
    }
};