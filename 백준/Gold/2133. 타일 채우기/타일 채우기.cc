#include <iostream>
#include <vector>

using namespace std;

int N;
int main()
{
    cin >> N;
    if(N % 2 == 1) 
    {
        cout << 0;
        return 0;
    }
    
    vector<int> dp(N+1);
    dp[0] = 1;
    dp[2] = 3;
    for(int i = 4; i < N+1; i+=2)
    {
        dp[i] = dp[i-2] * 3;
        for(int j = 4; j <= i; j+=2)
        {
            dp[i] = dp[i] + dp[i-j] * 2;
        }
    }

    cout << dp[N];
    return 0;
}