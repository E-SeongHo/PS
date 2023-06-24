class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        for(int i = 0; i < arr.size(); ++i)
        {
            if((arr[i]) % 2 == 0)
            {
                int key = arr[i] / 2;
                for(int j = 0; j < arr.size(); ++j)
                {
                    if(i == j) continue;
                    if(arr[j] == key)   return true;
                }
            }
        }
        return false;
    }
};