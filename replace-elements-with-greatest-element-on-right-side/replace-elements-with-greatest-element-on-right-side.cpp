class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        // In-Place operation
        // In-place Array operations help to reduce space complexity, 
        // and so are a class of techniques that pretty much everybody encounters regularly in interviews.
                
        for(int i = arr.size()-1; i > 0; --i)
        {
            if(arr[i] > arr[i-1]) arr[i-1] = arr[i];
        }
        
        for(int i = 0; i < arr.size()-1; ++i)
        {
            arr[i] = arr[i+1];
        }
        arr[arr.size()-1] = -1;
        
        return arr;
    }
};