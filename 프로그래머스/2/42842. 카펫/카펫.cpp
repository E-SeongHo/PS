#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    
    int sum = (brown + 4) / 2;
    int width = sum - 1;
    int height = 1;
    
    while(width >= height)
    {
        if(height - 2 > 0)
        {
            if((width - 2) * (height - 2) == yellow) 
            {
                return {width, height};
            }
        }
        
        width--;
        height++;
    }
    
    return {0, 0};
}