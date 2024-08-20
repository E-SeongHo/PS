#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> V;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    V.resize(N);
    for(int i = 0; i < N; ++i)
        cin >> V[i];

    vector<int> dp(N+1);

    for(int i = 1; i < N+1; ++i)
    {   
        int prev = 0;
        for(int j = 1; j < i; ++j)
        {
            if(V[j-1] < V[i-1])
            {
                prev = max(prev, dp[j]);
            }
        }
        dp[i] = prev + 1;
    }

    int idx = max_element(dp.begin(), dp.end()) - dp.begin();
    int cur = idx;
    
    vector<int> ret;
    while(dp[cur])
    {
        ret.push_back(V[cur-1]);

        int prev = 0;
        int prev_idx = 0;
        for(int i = 1; i < cur; ++i)
        {
            if(V[i-1] < V[cur-1])
            {
                if(dp[i] > prev)
                {
                    prev = dp[i];
                    prev_idx = i;
                }
            }
        }

        cur = prev_idx;
    }

    cout << dp[idx] << '\n';
    for(auto it = ret.rbegin(); it != ret.rend(); ++it)
    {
        cout << *it << " ";
    }

    return 0;
}