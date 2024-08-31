#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int M, N;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    vector<vector<int>> orders;
    int ans = 0;

    cin >> M >> N;
    for(int i = 0; i < M; ++i)
    {
        vector<int> v(N);
        for(int j = 0; j < N; ++j)
        {
            cin >> v[j];
        }

        vector<int> s(v);
        sort(s.begin(), s.end());

        vector<int> universe(N);
        for(int j = 0; j < N; ++j)
        {
            universe[j] = lower_bound(s.begin(), s.end(), v[j]) - s.begin();
        }

        for(auto& order : orders)
        {
            if(order == universe) ans++;
        }
        orders.push_back(universe);
    }

    cout << ans;
    return 0;
}