#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int T, N;
vector<pair<int, int>> V;

long long MinSum;
long long total_y;
long long total_x;

void dfs(int start, vector<int>& v)
{
    if(v.size() == N/2)
    {
        long long sum_y1 = 0;
        long long sum_x1 = 0;
        for(int idx : v)
        {
            sum_y1 += V[idx].first;
            sum_x1 += V[idx].second;
        }

        long long sum_y2 = total_y - sum_y1;
        long long sum_x2 = total_x - sum_x1;

        long long sum_y = sum_y1 - sum_y2;
        long long sum_x = sum_x1 - sum_x2;

        MinSum = min(MinSum, (sum_y * sum_y) + (sum_x * sum_x));
        
        return;
    }

    for(int i = start; i < N; ++i)
    {
        v.push_back(i);
        dfs(i+1, v);
        v.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> T;
    for(int t = 0; t < T; ++t)
    {
        cin >> N;
        V.resize(N);

        total_y = 0;
        total_x = 0;
        for(int i = 0; i < N; ++i)
        {
            int y, x;
            cin >> y >> x;
            V[i] = {y, x};

            total_y += y;
            total_x += x;
        }

        // v1 = (x1, y1) -> (x2, y2) = (x2 - x1, y2 - y1)
        // v2 = (x3, y3) -> (x4, y4) = (x4 - x3, y4 - y3)

        // v1 + v2 = ((x2 + x4) - (x1 + x3), (y2 + y4) - (y1 + y3))
        // => start points - end points

        MinSum = 9223372036854775807;
        vector<int> v;
        dfs(0, v);
        
        cout << fixed;
		cout.precision(15);
        cout << sqrt(MinSum) << '\n';
    }
    return 0;
}