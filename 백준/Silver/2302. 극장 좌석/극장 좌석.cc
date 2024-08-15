
#include <iostream>
#include <vector>

using namespace std;

int N, M;

int main()
{
    cin >> N >> M;
    vector<int> dp(N+1, 1);
    
    for(int i = 0; i < M; ++i)
    {
        int m;
        cin >> m;
        dp[m] = 0;
    }

    int ways = 1;
    int cnt = 1;
    for(int i = 1; i < N+1; ++i)
    {
        if(!dp[i]) 
        {
            if(dp[i-1]) ways *= dp[i-1];
            cnt = 1;
            continue;
        }

        if(cnt == 1) dp[i] = 1;
        else if(cnt == 2) dp[i] = 2;
        else dp[i] = dp[i-1] + dp[i-2];

        cnt++;
    }

    if(dp[N]) ways *= dp[N];
    cout << ways;

    return 0;
}