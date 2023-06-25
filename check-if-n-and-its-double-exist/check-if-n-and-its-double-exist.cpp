class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        
        // Hash map : O(N)
        unordered_set<int> s;
        for(auto e : arr)
        {
            if(s.find(e * 2) != s.end()) return true;
            s.insert(e);
        }
        
        for(int i = 0; i < arr.size(); ++i)
        {
            if(arr[i] % 2 == 0 && arr[i] != 0)
            {
                if(s.find(arr[i] / 2) != s.end()) return true;                     
            }
        }
        
        return false;
    }
};