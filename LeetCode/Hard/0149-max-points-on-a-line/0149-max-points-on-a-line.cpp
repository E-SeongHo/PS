class Solution {
public:
    int maxPoints(vector<vector<int>>& points) 
    {
        // THINK about "use float as a key?"
        sort(points.begin(), points.end());
        int cnt = 1;
        for(int i = 0; i < points.size(); i++)
        {
            unordered_map<float, int> hash;
            for(int j = i+1; j < points.size(); j++)
            {
                float dx = points[j][0] - points[i][0];
                float dy = points[j][1] - points[i][1];
                float slope = dy / dx;
                if(hash.find(slope) != hash.end())
                    hash[slope] = hash[slope] + 1;
                else
                    hash[slope] = 2;
                cnt = max(hash[slope], cnt);
            }
        }
        return cnt;
    }
};