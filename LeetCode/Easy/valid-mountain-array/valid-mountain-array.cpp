class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        
        // Brilliant solution!!
        
        // < Mountain Climb >
        // Two people climb from left and from right separately.
        // If they are climbing the same mountain,
        // they will meet at the same point.
        
        int front = 0;
        int back = arr.size()-1;
        
        if(arr.size() < 3) return false;
        
        while(front < arr.size()-2)
        {
            if(arr[front+1] > arr[front]) front++;
            else break;
        }
        while(back > 1)
        {
            if(arr[back-1] > arr[back]) back--;
            else break;
        }
        
        std::cout << front << " " << back << std::endl;
        return front == back;
    }
};