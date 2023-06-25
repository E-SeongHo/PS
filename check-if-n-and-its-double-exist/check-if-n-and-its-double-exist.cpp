class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        
        // Hash map : O(N)
        unordered_multiset<int> s;
        for(auto e : arr)   s.insert(e);
                
        for(int i = 0; i < arr.size(); ++i)
        {
            if(arr[i] % 2 == 0)
            {
                int key = arr[i] / 2;
                if(key == 0) 
                {
                    if(s.count(key) > 1) return true;
                }
                else
                {
                    if(s.find(key) != s.end()) return true;   
                }                    
            }
        }
        
        return false;
    }
};