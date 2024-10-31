#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> Taken;
vector<int> Cost;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N >> M;
    Taken.resize(N+1); Cost.resize(N+1);

    for(int i = 1; i < N+1; ++i)
        cin >> Taken[i];

    for(int i = 1; i < N+1; ++i)
        cin >> Cost[i];

    vector<int> dp(M+1, 200000000);
    dp[0] = 0;

    for(int i = 1; i < N+1; ++i)
    {
        vector<int> prev = dp;
        for(int j = 1; j < M+1; ++j)
        {
            if(j >= Taken[i])
            {
                dp[j] = min(prev[j], prev[j-Taken[i]] + Cost[i]);
            }
            else
            {
                dp[j] = min(prev[j], Cost[i]);
            }
        }
    }

    cout << dp[M];
    return 0;
}
