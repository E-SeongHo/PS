#include <iostream>
#include <vector>

using namespace std;

int N, K;
int S, Y;
vector<pair<int, int>> V(7);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> K;
    for(int i = 0; i < N; ++i)
    {
        cin >> S >> Y;
        if(S) V[Y].first++;
        else V[Y].second++;
    }

    int ans = 0;
    for(auto [male, female] : V)
    {
        ans += male/K;
        ans += female/K;

        if(male%K) ans++;
        if(female%K) ans++;
    }

    cout << ans;

    return 0;
}