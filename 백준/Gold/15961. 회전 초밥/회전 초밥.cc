#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int N, D, K, C;
vector<int> V;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> D >> K >> C;
    V.resize(N);

    for(int i = 0; i < N; ++i)
        cin >> V[i];
    
    int ans = 0;

    unordered_map<int, int> m;
    int cnt = 0;
    for(int i = 0; i < K; ++i)
    {
        if(++m[V[i]] == 1) cnt++;
    }

    ans = m[C] ? cnt : cnt+1;

    for(int i = K; i < N+K-1; ++i)
    {
        if(!--m[V[i-K]]) cnt--;

        if(++m[V[i%N]] == 1) cnt++;

        ans = max(ans, m[C] ? cnt : cnt+1);
    }

    cout << ans;
    return 0;
}
