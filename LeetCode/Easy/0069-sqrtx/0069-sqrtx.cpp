class Solution {
public:
    
    int mySqrtBruteForce(int x)
    {
        unsigned int root = 0;
        unsigned long long square = root * root;
        
        while(square <= x)
        {
            root++;
            square = root * root;
        }

        return root-1;
    }
    int mySqrtBinarySearch(int x)
    {
        if(x == 0) return 0;
        if(x == 1) return 1;

        int begin = 0;
        int end = x / 2;

        while(begin <= end)
        {
            long long root = begin + (end - begin)/2;
            long long square = root * root;

            if(x == square) return root;
            else if(x > square) begin = root + 1;
            else end = root - 1;
        }

        return begin-1;
    }
    int mySqrt(int x)  {
        
        return mySqrtBinarySearch(x);
        
        return mySqrtBruteForce(x);
    }
};