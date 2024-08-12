#include <iostream>
#include <vector>

using namespace std;

int N;
vector<long long> DP;

int main()
{
    // 5:51
    cin >> N;
    DP.resize(N+1);
    DP[1] = 1;

    for(int i = 2; i < N+1; ++i)
    {
        DP[i] = DP[i-1] + DP[i-2];
    }

    cout << DP[N];

    return 0;
}