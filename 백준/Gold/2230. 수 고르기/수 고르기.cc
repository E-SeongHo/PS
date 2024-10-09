#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> V;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N >> M;
    V.resize(N);
    for(int i = 0; i < N; ++i)
        cin >> V[i];

    sort(V.begin(), V.end());

    int ret = 2147483647;
    for(int i = 0; i < V.size(); ++i)
    {
        auto it = lower_bound(V.begin(), V.end(), V[i]+M);

        if(it != V.end()) ret = min(ret, *it - V[i]);
    }

    cout << ret;

    return 0;
}
