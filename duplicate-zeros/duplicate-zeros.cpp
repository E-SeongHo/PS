class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int cnt = count(arr.begin(), arr.end(), 0);
        for(int i = arr.size()-1; i >= 0; --i)
        {
            if(arr[i] == 0)
            {
                cnt--;
                if(i + cnt + 1 <= arr.size() - 1) 
                {
                    arr[i + cnt + 1] = 0;
                }
            }
            if(i + cnt <= arr.size() - 1) 
            {
                arr[i + cnt] = arr[i];
            }            
        }
    }
};