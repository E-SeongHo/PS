#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> V;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N;
    V.resize(N+1);
    for(int i = 1; i <= N; ++i)
        cin >> V[i];

    vector<vector<long long>> dp(N, vector<long long>(21, 0));
    dp[1][V[1]] = 1;

    for(int i = 2; i <= N-1; ++i)
    {
        for(int j = 0; j <= 20; ++j)
        {
            if(0 <= j-V[i] && j-V[i] <= 20) dp[i][j] += dp[i-1][j-V[i]];
            if(0 <= j+V[i] && j+V[i] <= 20) dp[i][j] += dp[i-1][j+V[i]];
        }
    }  
    
    cout << dp[N-1][V.back()];

    return 0;
}
