#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> DP;
int N;

int main()
{
    // 5:15
    cin >> N;
    DP.resize(N+1);

    DP[1] = {0, 0};
    for(int i = 2; i < N+1; ++i)
    {
        int n = 99999999;
        int from = -1;
        if(i%2 == 0 && DP[i/2].first < n) 
        {
            n = DP[i/2].first;
            from = i/2;
        }
        if(i%3 == 0 && DP[i/3].first < n) 
        {
            n = DP[i/3].first;
            from = i/3;
        }

        if(DP[i-1].first < n)
        {
            n = DP[i-1].first;
            from = i-1;
        }
        DP[i] = {n+1, from};
    }

    cout << DP[N].first << '\n';
    cout << N << " ";
    int idx = N;
    while(idx > 1)
    {
        cout << DP[idx].second << " ";
        idx = DP[idx].second;
    }

    // 5:45
    return 0;
}