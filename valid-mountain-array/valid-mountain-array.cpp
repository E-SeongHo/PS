class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        
        if(arr.size() < 3) return false;
        if(arr[1] < arr[0]) return false;
        if(arr[arr.size()-1] > arr[arr.size()-2]) return false;
        
        bool increasing = true;
        
        for(int i = 0; i < arr.size()-1; ++i)
        {
            if(arr[i] == arr[i+1]) return false;
            if(increasing)
            {
                if(arr[i+1] < arr[i])   increasing = false;
            }
            else
            {
                if(arr[i+1] > arr[i]) return false;
            }
        }
        
        
        return true;
    }
};