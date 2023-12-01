#include <iostream>
#include <vector>

using namespace std;
const int r = 10007;

// Time Complexity : O(N), Space Complexity : O(N)
int main()
{
    int N;
    cin >> N;
    
    vector<int> dp(N+1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 3;

    for(int i = 3; i < N+1; ++i)
    {
        dp[i] = ((dp[i-1]) % r + (dp[i-2]*2) % r) % r;
    }

    cout << dp[N];
    return 0;
}