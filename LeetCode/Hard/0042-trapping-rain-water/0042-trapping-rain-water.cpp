class Solution 
{
public:
    int trap(vector<int>& height) 
    {        
        // Solution2) Two pointers approach
        
        int lp = 0; 
        int rp = height.size()-1;
        int left = height[lp];
        int right = height[height.size()-1];
        int sum = 0;
        
        while(lp < rp)
        {
            if(height[lp] <= height[rp])
            {
                if(height[lp] <= left) sum += left - height[lp];
                else left = height[lp];
                
                lp++;
            }
            else
            {
                if(height[rp] <= height[lp])
                {
                    if(height[rp] <= right) sum += right - height[rp];
                    else right = height[rp];
                    
                    rp--;
                }
            }
        }
        return sum;
        
    }
};