#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> V;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    V.resize(N);

    for(int i = 0; i < N; ++i)
        cin >> V[i];

    sort(V.begin(), V.end());

    long long ans = 0;
    for(int i = 0; i < N-2; ++i)
    {
        for(int j = i+1; j < N-1; ++j)
        {
            int two_sum = V[i] + V[j];
            int cnt = upper_bound(V.begin()+j+1, V.end(), -two_sum) - lower_bound(V.begin()+j+1, V.end(), -two_sum);

            ans += cnt;
        }
    }

    cout << ans;
    return 0;
}