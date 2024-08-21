#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> P;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    P.resize(N+1);

    for(int i = 1; i < N+1; ++i)
        cin >> P[i];

    vector<int> dp(N+1);

    dp[0] = 0;
    dp[1] = P[1];

    // O(N^2)
    for(int i = 2; i < N+1; ++i)
    {
        for(int j = 1; j < N+1; ++j)
        {
            if(i-j < 0) break;

            dp[i] = max(dp[i], dp[i-j] + P[j]);
        }
    }
    
    cout << dp[N];

    return 0;
}