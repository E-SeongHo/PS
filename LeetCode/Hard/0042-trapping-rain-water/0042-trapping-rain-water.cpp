class Solution 
{
public:
    int trap(vector<int>& height) 
    {
        stack<int> st;
        int left = height[0];
        st.push(left);

        int water = 0;
        for(int i = 1; i < height.size(); i++)
        {
            if(height[i] >= left)
            {
                while(!st.empty())
                {
                    int block = st.top();
                    st.pop();
                    water += left - block;
                }
                left = height[i];
            }
            st.push(height[i]);
        }
        
        // process left overs
        int right = st.top(); 
        st.pop();
        int sum = 0;
        while(!st.empty())
        {
            int block = st.top();
            st.pop();
            if(block < right)
            {
                sum += right - block;
            }
            else
            {
                water += sum;
                sum = 0;
                right = block;
            }
        }
        return water;
    }
};