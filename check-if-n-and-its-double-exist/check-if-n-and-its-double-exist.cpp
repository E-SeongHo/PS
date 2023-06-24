class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        
        // Binary search : O(logN)
        sort(arr.begin(), arr.end());
        
        for(int i = arr.size() - 1; i >= 0; --i) 
        {
            if(arr[i] % 2 == 0)
            {
                int key = arr[i] / 2;
                int begin = 0;
                int end = arr.size() - 1;
                while(begin <= end)
                {
                    int mid = (begin + end) / 2;
                    if(arr[mid] == key && mid != i) return true;
                    else if(key < arr[mid]) end = mid - 1;
                    else begin = mid + 1;
                }
            }
        }
        
        return false;
    }
};