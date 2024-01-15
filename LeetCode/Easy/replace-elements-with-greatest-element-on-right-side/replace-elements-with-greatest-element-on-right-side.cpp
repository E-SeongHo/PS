class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        // In-Place operation
        // In-place Array operations help to reduce space complexity, 
        // and so are a class of techniques that pretty much everybody encounters regularly in interviews.
                
        // Solution 2
        // By simply using one additional memory cell for int (8 bytes), you can significantly improve time complexity.

        arr[0] = -1;
        int temp = 0;
        for(int i = arr.size()-1; i > 0; --i)
        {
            temp = arr[i];
            arr[i] = arr[0];
            arr[0] = max(arr[0], temp);
        }
        
        
        return arr;
    }
};